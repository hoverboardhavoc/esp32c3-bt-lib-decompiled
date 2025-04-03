/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_trunc_ind(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
  (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar2,2,*(code **)(_r_ip_funcs_p + 0x3d8));
  pvVar1 = (void *)(**(code **)(_r_modules_funcs_p + 200))
                             (0x201,0,0xff,0x2c,*(code **)(_r_modules_funcs_p + 200));
  pvVar1 = memcpy(pvVar1,(void *)(iVar2 + 0x58),0x2c);
  *(undefined1 *)((int)pvVar1 + 0x16) = 2;
  *(undefined1 *)((int)pvVar1 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
                    /* WARNING: Could not recover jumptable at 0x00012588. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))();
  return;
}

