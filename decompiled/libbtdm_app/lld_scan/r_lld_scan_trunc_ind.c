/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
                    /* WARNING: Could not recover jumptable at 0x00012530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))();
  return;
}

