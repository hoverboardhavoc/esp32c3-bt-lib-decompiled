/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
                    /* WARNING: Could not recover jumptable at 0x0001163a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
  return;
}

