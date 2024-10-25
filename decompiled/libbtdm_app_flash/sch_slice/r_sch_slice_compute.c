/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = _r_sdk_config_get_opts;
  _r_sdk_config_get_opts = CONCAT22(r_sdk_config_get_opts_2,_DAT_00011060);
  _sch_slice_params = 0xffffffff;
  uVar1 = 0xffff;
  for (; uVar5 != 0; uVar5 = uVar5 & ~(1 << (uVar4 & 0x1f))) {
    iVar2 = __clzsi2(uVar5);
    uVar4 = 0x1f - iVar2;
    iVar2 = r_sdk_config_get_opts();
    if ((int)(uint)*(byte *)(iVar2 + 0xd) <= (int)uVar4) {
      r_assert_err(0,"sch_slice.c",0xb6);
    }
    if (*(int *)(r_assert_err + uVar4 * 8) != 0) {
      uVar3 = *(int *)(r_assert_err + uVar4 * 8) - *(ushort *)(memset + uVar4 * 8) / 0x271 & 0xffff;
      if (2 < uVar3) {
        uVar3 = uVar3 - 2 & 0xffff;
      }
      if (uVar3 < uVar1) {
        uVar1 = uVar3;
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

