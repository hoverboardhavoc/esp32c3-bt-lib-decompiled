/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  
  uVar5 = _r_sdk_config_get_opts;
  _r_sdk_config_get_opts = CONCAT22(r_sdk_config_get_opts_2,_DAT_00011060);
  _sch_slice_params = 0xffffffff;
  uVar1 = 0xffff;
  for (; uVar5 != 0; uVar5 = uVar5 & ~(1 << (uVar2 & 0x1f))) {
    iVar3 = __clzsi2(uVar5);
    uVar2 = 0x1f - iVar3;
    iVar3 = r_sdk_config_get_opts();
    if ((int)(uint)*(byte *)(iVar3 + 0xd) <= (int)uVar2) {
      r_assert_err(0,0x10000,0xb6);
    }
    if (*(int *)(r_assert_err + uVar2 * 8) != 0) {
      uVar4 = *(int *)(r_assert_err + uVar2 * 8) - *(ushort *)(memset + uVar2 * 8) / 0x271 & 0xffff;
      if (2 < uVar4) {
        uVar4 = uVar4 - 2 & 0xffff;
      }
      if (uVar4 < uVar1) {
        uVar1 = uVar4;
      }
    }
  }
  uVar5 = _r_sdk_config_get_opts & 0xffff;
  if (uVar1 * 0x271 < (_r_sdk_config_get_opts & 0xffff)) {
    uVar5 = uVar1 * 0x271;
  }
  _r_sdk_config_get_opts = CONCAT22(r_sdk_config_get_opts_2,(short)uVar5);
  return;
}

