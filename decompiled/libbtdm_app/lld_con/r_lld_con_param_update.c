/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_param_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_param_update
          (int param_1,int param_2,int param_3,int param_4,undefined2 param_5,int param_6,
          undefined2 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(undefined1 *)(iVar1 + 0x46) = 1;
      *(undefined2 *)(iVar1 + 0x44) = param_7;
      *(short *)(iVar1 + 0x40) = (short)(param_2 << 2);
      *(short *)(iVar1 + 0x3c) = (short)(param_3 << 2);
      *(int *)(iVar1 + 0x34) = param_4 << 2;
      *(undefined2 *)(iVar1 + 0x3e) = param_5;
      *(int *)(iVar1 + 0x38) = param_6 << 5;
      if (((uint)(param_4 << 2) < *(uint *)(iVar1 + 100)) && (1 < *(byte *)(iVar1 + 0x94))) {
        (**(code **)(_r_ip_funcs_p + 0x3c4))(param_1,*(code **)(_r_ip_funcs_p + 0x3c4));
      }
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0xf51,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(undefined2 *)(iVar1 + 0x42) = 0;
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

