/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_compute(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = _r_plf_funcs_p;
  _r_plf_funcs_p = CONCAT22(r_plf_funcs_p_2,_DAT_00011060);
  _sch_slice_params = 0xffffffff;
  uVar1 = 0xffff;
  for (; uVar5 != 0; uVar5 = uVar5 & ~(1 << (uVar4 & 0x1f))) {
    iVar2 = __clzsi2(uVar5);
    uVar4 = 0x1f - iVar2;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((int)(uint)*(byte *)(iVar2 + 0xd) <= (int)uVar4) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_slice.c",0xb6,*(code **)(_r_plf_funcs_p + 8));
    }
    if (*(int *)(memset + uVar4 * 8) != 0) {
      uVar3 = *(int *)(memset + uVar4 * 8) - *(ushort *)(&rwip_param + uVar4 * 8) / 0x271 & 0xffff;
      if (2 < uVar3) {
        uVar3 = uVar3 - 2 & 0xffff;
      }
      if (uVar3 < uVar1) {
        uVar1 = uVar3;
      }
    }
  }
  uVar5 = _r_plf_funcs_p & 0xffff;
  if (uVar1 * 0x271 < (_r_plf_funcs_p & 0xffff)) {
    uVar5 = uVar1 * 0x271;
  }
  _r_plf_funcs_p = CONCAT22(r_plf_funcs_p_2,(short)uVar5);
  return;
}

