/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_start_eco(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined1 auStack_21 [9];
  
  auStack_21[0] = 0xc;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  pcVar3 = *(code **)(_r_ip_funcs_p + 0x7d8);
  *(undefined4 *)(iVar1 + 0x50) = uVar2;
  *(undefined2 *)(iVar1 + (param_1 + 0x10) * 2 + 8) = 0;
  (*pcVar3)(param_1,pcVar3);
  (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x828))
                    (1,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  if (iVar1 == 0) {
    iVar1 = r_lld_con_start(param_1,param_2);
    auStack_21[0] = (undefined1)iVar1;
    if ((iVar1 == 0) && (*(int *)(&lld_con_env + param_1 * 4) != 0)) {
      *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
    }
    (**(code **)(_r_ip_funcs_p + 0x828))
              (0,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  }
  return auStack_21[0];
}

