#include <wiiu.h>

extern int main(void);

extern void __wiiu_dynlib_install();
extern void __wiiu_dynlib_uninstall();

extern void __wiiu_syscall_install();
extern void __wiiu_syscall_uninstall();

extern void __wiiu_exception_handlers_install();
extern void __wiiu_exception_handlers_uninstall();

int _start(int argc, char** argv) {
    __wiiu_dynlib_install();
    __wiiu_syscall_install();
    __wiiu_exception_handlers_install();

    int ret = main();

    __wiiu_exception_handlers_uninstall();
    __wiiu_syscall_uninstall();
    __wiiu_dynlib_uninstall();

    return ret;
}