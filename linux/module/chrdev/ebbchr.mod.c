#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe68a66b1, "module_layout" },
	{ 0xef83ec51, "class_unregister" },
	{ 0x907ada93, "device_destroy" },
	{ 0x2e0c13be, "__mutex_init" },
	{ 0xb267629f, "class_destroy" },
	{ 0xf46832fc, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x32528423, "__class_create" },
	{ 0xe0cce7f4, "__register_chrdev" },
	{ 0xb708e171, "mutex_trylock" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xd0d8621b, "strlen" },
	{ 0x91715312, "sprintf" },
	{ 0x13f13805, "mutex_unlock" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "05E8FE9AADA4DFBB2475170");
