#pragma once
#include "../utils/no_crt.hpp"
#include "../utils/xorstr.hpp"

#include "memory.hpp"

namespace il2cpp {
	namespace methods {
		using il2cpp_domain_get = uintptr_t (*)();

		static auto domain_get = LI_FIND_DEF(il2cpp_domain_get);

		using il2cpp_class_get_methods = uintptr_t (*)(uintptr_t, uintptr_t*);

		static auto class_get_methods = LI_FIND_DEF(il2cpp_class_get_methods);

		using il2cpp_method_get_param_count = int (*)(uintptr_t);

		static auto method_get_param_count = LI_FIND_DEF(il2cpp_method_get_param_count);

		using il2cpp_assembly_get_image = uintptr_t (*)(uintptr_t);

		static auto assembly_get_image = LI_FIND_DEF(il2cpp_assembly_get_image);

		using il2cpp_domain_get_assemblies = uintptr_t * (*)(void* domain, uintptr_t* size);

		static auto domain_get_assemblies = LI_FIND_DEF(il2cpp_domain_get_assemblies);

		using il2cpp_object_new = uintptr_t(*)(uintptr_t);

		static auto object_new = LI_FIND_DEF(il2cpp_object_new);

		using il2cpp_class_from_name = uintptr_t (*)(uintptr_t, const char*, const char*);

		static auto class_from_name = LI_FIND_DEF(il2cpp_class_from_name);

		using il2cpp_resolve_icall = uintptr_t (*)(const char*);

		static auto resolve_icall = LI_FIND_DEF(il2cpp_resolve_icall);

		using il2cpp_field_static_get_value = uintptr_t (*)(uintptr_t, uintptr_t*);

		static auto field_static_get_value = LI_FIND_DEF(il2cpp_field_static_get_value);

		using il2cpp_class_get_fields = uintptr_t (*)(uintptr_t, uintptr_t*);

		static auto class_get_fields = LI_FIND_DEF(il2cpp_class_get_fields);

		using il2cpp_field_get_offset = uintptr_t (*)(uintptr_t);

		static auto field_get_offset = LI_FIND_DEF(il2cpp_field_get_offset);

		using il2cpp_runtime_class_init = uintptr_t (*)(uintptr_t);

		static auto runtime_class_init = LI_FIND_DEF(il2cpp_runtime_class_init);

		static auto intialize_method = rb::pattern::find(_("GameAssembly.dll"), _("48 83 EC 48 48 8B 05 ? ? ? ? 48 63 90 ? ? ? ?"));

		using il2cpp_string_new_wrapper = uintptr_t(*)(const char*);
		static auto new_string = LI_FIND_DEF(il2cpp_string_new_wrapper);
	}

	void init() {
		methods::intialize_method = rb::pattern::find(_("GameAssembly.dll"), _("48 83 EC 48 48 8B 05 ? ? ? ? 48 63 90 ? ? ? ?"));

		using il2cpp_string_new_wrapper = uintptr_t(*)(const char*);
		methods::new_string = LI_FIND_DEF(il2cpp_string_new_wrapper);

		using il2cpp_domain_get = uintptr_t(*)();

		methods::domain_get = LI_FIND_DEF(il2cpp_domain_get);

		using il2cpp_class_get_methods = uintptr_t(*)(uintptr_t, uintptr_t*);

		methods::class_get_methods = LI_FIND_DEF(il2cpp_class_get_methods);

		using il2cpp_method_get_param_count = int (*)(uintptr_t);

		methods::method_get_param_count = LI_FIND_DEF(il2cpp_method_get_param_count);

		using il2cpp_assembly_get_image = uintptr_t(*)(uintptr_t);

		methods::assembly_get_image = LI_FIND_DEF(il2cpp_assembly_get_image);

		using il2cpp_domain_get_assemblies = uintptr_t * (*)(void* domain, uintptr_t* size);

		methods::domain_get_assemblies = LI_FIND_DEF(il2cpp_domain_get_assemblies);

		using il2cpp_class_from_name = uintptr_t(*)(uintptr_t, const char*, const char*);

		methods::class_from_name = LI_FIND_DEF(il2cpp_class_from_name);

		using il2cpp_resolve_icall = uintptr_t(*)(const char*);

		methods::resolve_icall = LI_FIND_DEF(il2cpp_resolve_icall);

		using il2cpp_field_static_get_value = uintptr_t(*)(uintptr_t, uintptr_t*);

		methods::field_static_get_value = LI_FIND_DEF(il2cpp_field_static_get_value);

		using il2cpp_class_get_fields = uintptr_t(*)(uintptr_t, uintptr_t*);

		methods::class_get_fields = LI_FIND_DEF(il2cpp_class_get_fields);

		using il2cpp_field_get_offset = uintptr_t(*)(uintptr_t);

		methods::field_get_offset = LI_FIND_DEF(il2cpp_field_get_offset);

		using il2cpp_object_new = uintptr_t(*)(uintptr_t);

		methods::object_new = LI_FIND_DEF(il2cpp_object_new);

		using il2cpp_runtime_class_init = uintptr_t(*)(uintptr_t);

		methods::runtime_class_init = LI_FIND_DEF(il2cpp_runtime_class_init);
	}

	uintptr_t init_class(const char* name, const char* name_space = _("")) {
		 
		uintptr_t domain = methods::domain_get();

		uintptr_t nrofassemblies = 0;
		uintptr_t* assemblies;
		assemblies = methods::domain_get_assemblies( (void*)domain, &nrofassemblies);

		for (int i = 0; i < nrofassemblies; i++) {
			uintptr_t img = methods::assembly_get_image( assemblies[i]);

			uintptr_t kl = methods::class_from_name( img, name_space, name);
			if (!kl) continue;

			return kl;
		}
		return 0;
	}

	//selected_argument is the argument to be checked if the name is right
	uintptr_t method(const char* kl, const char* name, int argument_number = -1, char* arg_name = _(""), const char* name_space = _(""), int selected_argument = -1) {
		uintptr_t iter = 0;
		uintptr_t f;
		auto klass = init_class(kl, name_space);

		while (f = methods::class_get_methods(klass, &iter)) {

			char* st = *reinterpret_cast<char**>(f + 0x10);

			if (m_strcmp(st, (char*)name)) {
				if (selected_argument >= 0 && arg_name) {
					uintptr_t args = mem::read<uintptr_t>(f + 0x28);
					int method_count = methods::method_get_param_count( f);
					if (selected_argument > method_count || (argument_number >= 0 && method_count != argument_number)) continue;

					char* argname;
					if (method_count > 0) {
						argname = *reinterpret_cast<char**>(args + (selected_argument - 1) * 0x18);
					}
					else
						argname = (char*)_("-");

					if (!argname || !m_strcmp(argname, arg_name)) continue;
				}

				return f;
			}
		}
		return 0;
	}

	uintptr_t hook( void* our_func, const char* function_to_hook,const char* class_to_hook, const char* name_space = _(""), int argument_number = -1, char* argument_name = _("")) {
		auto il2cpp_method = method(class_to_hook, function_to_hook, argument_number, argument_name, name_space);

		*reinterpret_cast<void**>(il2cpp_method) = our_func;
		return il2cpp_method;
	}

	uintptr_t field(uintptr_t klass, char* field_name, bool get_offset = true) {
		uintptr_t out = 0;
		uintptr_t il2cpp_field;

		while (il2cpp_field = methods::class_get_fields( klass, &out)) {

			char* name = (char*)*reinterpret_cast<uintptr_t*>(il2cpp_field);
			if (!name)
				break;

			if (!m_strcmp(name, field_name)) {
				continue;
			}
			if (!get_offset)
				return il2cpp_field;

			uintptr_t offset = methods::field_get_offset( il2cpp_field);
			return offset;
		}
		return 0;
	}

	uintptr_t value(const char* kl, char* name, bool get_offset = true) {

		auto klass = init_class(kl);

		if (get_offset) {
			auto field_offset = field(klass, name);
			return field_offset;
		}
		else
		{
			auto _field = field(klass, name, false);

			uintptr_t ret;
			methods::field_static_get_value(_field, &ret);
			return ret;
		}
		return 0;
	}
}

uintptr_t mem::hook_virtual_function(const char* classname, const char* function_to_hook, void* our_func, const char* name_space = _("")) {
	uintptr_t search = *reinterpret_cast<uintptr_t*>(il2cpp::method(classname, function_to_hook, -1, _(""), name_space));
	uintptr_t table = il2cpp::init_class(classname, name_space);

	if (search == (uintptr_t)our_func)
		return (uintptr_t)our_func;

	for (uintptr_t i = table; i <= table + 0x1500; i += 0x1) {
		uintptr_t addr = *reinterpret_cast<uintptr_t*>(i);
		if (addr == search) {
			*reinterpret_cast<uintptr_t*>(i) = (uintptr_t)our_func;
			return addr;
		}
	}
}