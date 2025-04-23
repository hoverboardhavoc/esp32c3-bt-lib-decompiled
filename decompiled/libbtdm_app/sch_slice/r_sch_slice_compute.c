/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  _r_plf_funcs_p = CONCAT22(r_plf_funcs_p_2,_DAT_0001105c);
  _sch_slice_params = 0xffffffff;
  uVar1 = 0xffff;
  for (; uVar5 != 0; uVar5 = uVar5 & ~(1 << (uVar4 & 0x1f))) {
    iVar2 = __clzsi2(uVar5);
    uVar4 = 0x1f - iVar2;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((int)(uint)*(byte *)(iVar2 + 0xd) <= (int)uVar4) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xb6,*(code **)(_r_plf_funcs_p + 8));
    }
    if (*(int *)(__clzsi2 + uVar4 * 8) != 0) {
      uVar3 = *(int *)(__clzsi2 + uVar4 * 8) - *(ushort *)(memset + uVar4 * 8) / 0x271 & 0xffff;
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

