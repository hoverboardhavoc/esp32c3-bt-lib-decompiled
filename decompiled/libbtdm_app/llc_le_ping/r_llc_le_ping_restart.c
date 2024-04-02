/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> llc_le_ping.o -> r_llc_le_ping_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_le_ping_restart(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(char *)(iVar3 + 0x1c) != '\0') && ((*(ushort *)(iVar2 + 0x42) & 0x20) != 0)) {
    uVar1 = param_1 << 8 | 1;
    (**(code **)(_r_modules_funcs_p + 0xc4))
              (0x102,uVar1,*(undefined2 *)(iVar2 + 0x3e),*(code **)(_r_modules_funcs_p + 0xc4));
                    /* WARNING: Could not recover jumptable at 0x00010074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xc4))(0x103,uVar1,*(undefined2 *)(iVar2 + 0x40));
    return;
  }
  return;
}

