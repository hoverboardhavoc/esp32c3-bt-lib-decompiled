/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_data_flow_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_data_flow_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) & 0xffef | (ushort)(param_2 << 4);
    if ((((param_2 != 0) &&
         ((**(code **)(_r_ip_funcs_p + 0x3d0))(param_1,*(code **)(_r_ip_funcs_p + 0x3d0)),
         *(char *)(iVar1 + 0x92) != '\0')) && (*(char *)(iVar1 + 0x8f) == '\0')) &&
       (((*(ushort *)(iVar1 + 0x84) & 1) != 0 && (*(char *)(iVar1 + 0x96) != '\0')))) {
      iVar4 = *(int *)(&lld_con_env + param_1 * 4);
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        while (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
          if (*(short *)(iVar1 + 0x7e) == 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xeae,*(code **)(_r_plf_funcs_p + 8));
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,iVar2,0,*(code **)(_r_ip_funcs_p + 0x3a8));
        uVar3 = 0;
        goto _L766;
      }
    }
    uVar3 = 0;
  }
_L766:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

