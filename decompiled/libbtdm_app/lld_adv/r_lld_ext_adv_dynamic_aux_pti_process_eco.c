/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_aux_pti_process_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_aux_pti_process_eco(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  r_lld_ext_adv_dynamic_aux_pti_process();
  if (((param_1 != 0) && ((param_1 & 1) == 0)) && ((param_1 & 2) != 0)) {
    do {
      bVar1 = *(byte *)(param_3 + 9);
      param_2 = param_2 + 1 & 0xff;
      if ((bVar1 & 0xf0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = param_2 * 0xe + 10;
      uVar2 = *(ushort *)(iVar3 + iVar5);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar5) = uVar2 & 0xf0ff | (ushort)bVar1 << 8;
      bVar1 = *(byte *)(param_3 + 10);
      if ((bVar1 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar3 + iVar5);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar4 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar3 + iVar5) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
      iVar3 = (*pcVar4)(0x1400,pcVar4);
    } while ((*(ushort *)(iVar3 + param_2 * 0xe) & 0x7fff) != 0);
  }
  return;
}

