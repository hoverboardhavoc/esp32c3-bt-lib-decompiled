/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_aux_pti_process_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_aux_pti_process_eco(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  
  r_lld_ext_adv_dynamic_aux_pti_process();
  if (((param_1 != 0) && ((param_1 & 1) == 0)) && ((param_1 & 2) != 0)) {
    do {
      param_2 = param_2 + 1 & 0xff;
      uVar5 = (uint)*(byte *)(param_3 + 9) << 8;
      if ((uVar5 & 0xfffff0ff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = param_2 * 0xe + 10;
      uVar1 = *(ushort *)(iVar2 + iVar4);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar2 + iVar4) = uVar1 & 0xf0ff | (ushort)uVar5;
      uVar5 = (uint)*(byte *)(param_3 + 10) << 0xc;
      if ((uVar5 & 0xffffefff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + iVar4);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar3 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar2 + iVar4) = uVar1 & 0xefff | (ushort)uVar5;
      iVar2 = (*pcVar3)(0x1400,pcVar3);
    } while ((*(ushort *)(iVar2 + param_2 * 0xe) & 0x7fff) != 0);
  }
  return;
}

