/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_aux_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_aux_pti_process(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    do {
      param_2 = param_2 + 1 & 0xff;
      uVar5 = (uint)*(byte *)(param_3 + 7) << 8;
      if ((uVar5 & 0xfffff0ff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = param_2 * 0xe + 10;
      uVar1 = *(ushort *)(iVar2 + iVar4);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar2 + iVar4) = uVar1 & 0xf0ff | (ushort)uVar5;
      uVar5 = (uint)*(byte *)(param_3 + 8) << 0xc;
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
  else {
    if ((param_1 & 1) == 0) {
      if ((param_1 & 2) == 0) {
        return;
      }
      uVar5 = (uint)*(byte *)(param_3 + 9) << 8;
      if ((uVar5 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar2 = (param_2 + 1 & 0xff) * 0xe + 10;
      uVar1 = *(ushort *)(iVar4 + iVar2);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar2) = uVar1 & 0xf0ff | (ushort)uVar5;
      uVar5 = (uint)*(byte *)(param_3 + 10) << 0xc;
      if ((uVar5 & 0xffffefff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar2) & 0xefff | (ushort)uVar5;
      pcVar3 = *(code **)(_r_plf_funcs_p + 0xbc);
    }
    else {
      uVar5 = (uint)*(byte *)(param_3 + 0xb) << 8;
      if ((uVar5 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar2 = (param_2 + 1 & 0xff) * 0xe + 10;
      uVar1 = *(ushort *)(iVar4 + iVar2);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar2) = uVar1 & 0xf0ff | (ushort)uVar5;
      uVar5 = (uint)*(byte *)(param_3 + 0xc) << 0xc;
      if ((uVar5 & 0xffffefff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar2) & 0xefff | (ushort)uVar5;
      pcVar3 = *(code **)(_r_plf_funcs_p + 0xbc);
    }
    iVar4 = (*pcVar3)(0x1400,pcVar3);
    *(ushort *)(iVar4 + iVar2) = uVar1;
  }
  return;
}

