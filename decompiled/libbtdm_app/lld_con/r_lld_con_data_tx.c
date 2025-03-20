/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_data_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_data_tx(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar1 != 0) {
    (**(code **)(_r_modules_funcs_p + 0x44))
              (iVar1 + 0x28,param_2,*(code **)(_r_modules_funcs_p + 0x44));
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) | 8;
    (**(code **)(_r_ip_funcs_p + 0x3d0))(param_1,*(code **)(_r_ip_funcs_p + 0x3d0));
    if (((*(char *)(iVar1 + 0x8f) == '\0') && ((*(ushort *)(iVar1 + 0x84) & 1) != 0)) &&
       (*(char *)(iVar1 + 0x96) != '\0')) {
      iVar4 = *(int *)(&lld_con_env + param_1 * 4);
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        while (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
          if (*(short *)(iVar1 + 0x7e) == 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xe8e,*(code **)(_r_plf_funcs_p + 8));
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,iVar2,0,*(code **)(_r_ip_funcs_p + 0x3a8));
        uVar3 = 0;
        goto _L751;
      }
    }
    uVar3 = 0;
  }
_L751:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

