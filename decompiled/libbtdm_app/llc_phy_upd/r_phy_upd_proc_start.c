/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_phy_upd_proc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_phy_upd_proc_start(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
  *(undefined1 *)(puVar2 + 1) = 9;
  (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
  *puVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  *(undefined1 *)((int)puVar2 + 0xb) = *(undefined1 *)(iVar3 + 0x27);
  uVar1 = *(undefined1 *)(iVar3 + 0x26);
  *(undefined2 *)(puVar2 + 4) = 0;
  *(undefined1 *)((int)puVar2 + 0xe) = 0;
  *(undefined1 *)((int)puVar2 + 10) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0001161c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2);
  return;
}

