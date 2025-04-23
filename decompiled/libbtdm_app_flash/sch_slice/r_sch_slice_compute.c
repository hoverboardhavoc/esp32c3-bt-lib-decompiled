/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_slice.o -> r_sch_slice_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_compute(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = ___clzsi2;
  ___clzsi2 = CONCAT22(__clzsi2_2,_DAT_0001105c);
  _sch_slice_params = 0xffffffff;
  uVar1 = 0xffff;
  for (; uVar5 != 0; uVar5 = uVar5 & ~(1 << (uVar2 & 0x1f))) {
    iVar3 = __clzsi2(uVar5);
    uVar2 = 0x1f - iVar3;
    iVar3 = r_sdk_config_get_opts();
    if ((int)(uint)*(byte *)(iVar3 + 0xd) <= (int)uVar2) {
      r_assert_err(0,0x10000,0xb6);
    }
    if (*(int *)(r_sdk_config_get_opts + uVar2 * 8) != 0) {
      uVar4 = *(int *)(r_sdk_config_get_opts + uVar2 * 8) -
              *(ushort *)(r_assert_err + uVar2 * 8) / 0x271 & 0xffff;
      if (2 < uVar4) {
        uVar4 = uVar4 - 2 & 0xffff;
      }
      if (uVar4 < uVar1) {
        uVar1 = uVar4;
      }
    }
  }
  uVar5 = ___clzsi2 & 0xffff;
  if (uVar1 * 0x271 < (___clzsi2 & 0xffff)) {
    uVar5 = uVar1 * 0x271;
  }
  ___clzsi2 = CONCAT22(__clzsi2_2,(short)uVar5);
  return;
}

