/*
 * Last changed at upstream commit 0a08c4b32f3666003080b662a1a61794da24ff0f
 * https://github.com/espressif/esp32c3-bt-lib/commit/0a08c4b32f3666003080b662a1a61794da24ff0f
 * Upstream date: 2026-05-25 14:11:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(51d9dfde)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_llcp_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_llcp_tx(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar3 = 0xc;
  }
  else {
    if (*(int *)(iVar1 + 0x24) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xfac,*(code **)(_r_plf_funcs_p + 8));
    }
    *(undefined4 *)(iVar1 + 0x24) = param_2;
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) | 8;
    (**(code **)(_r_ip_funcs_p + 0x3d0))(param_1,*(code **)(_r_ip_funcs_p + 0x3d0));
    if (((*(char *)(iVar1 + 0x8f) == '\0') && ((*(ushort *)(iVar1 + 0x84) & 1) != 0)) &&
       (*(char *)(iVar1 + 0x96) != '\0')) {
      uVar4 = *(undefined4 *)(&lld_con_env + param_1 * 4);
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(uVar4,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        while (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
          if (*(short *)(iVar1 + 0x7e) == 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xfc8,*(code **)(_r_plf_funcs_p + 8));
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,iVar2,0,*(code **)(_r_ip_funcs_p + 0x3a8));
        uVar3 = 0;
        goto _L775;
      }
    }
    uVar3 = 0;
  }
_L775:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

