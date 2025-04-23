/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_data_flow_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_data_flow_set(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) & 0xffef | (ushort)(param_2 << 4);
    if ((((param_2 != 0) &&
         ((**(code **)(_r_ip_funcs_p + 0x3d0))(param_1,*(code **)(_r_ip_funcs_p + 0x3d0)),
         *(char *)(iVar1 + 0x92) != '\0')) && (*(char *)(iVar1 + 0x8f) == '\0')) &&
       (((*(ushort *)(iVar1 + 0x84) & 1) != 0 && (*(char *)(iVar1 + 0x96) != '\0')))) {
      iVar4 = *(int *)(&lld_con_env + param_1 * 4);
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar3 & 0xfffffffU)) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        while (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar3 & 0xfffffffU)) {
          if (*(short *)(iVar1 + 0x7e) == 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xed5,*(code **)(_r_plf_funcs_p + 8));
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,iVar3,0,*(code **)(_r_ip_funcs_p + 0x3a8));
      }
    }
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

