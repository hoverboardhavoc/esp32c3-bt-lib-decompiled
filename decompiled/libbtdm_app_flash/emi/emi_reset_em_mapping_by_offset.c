/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> emi_reset_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void emi_reset_em_mapping_by_offset(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar2 = r_emi_get_em_mapping_idx_by_offset();
  uVar3 = _DAT_600312c4;
  uVar4 = uVar2;
  if (0x1f < (int)uVar2) {
    if ((int)uVar2 < 0x30) {
      uVar3 = _DAT_600312c8;
      uVar4 = uVar2 - 0x20;
    }
    else {
      uVar3 = _DAT_60031300;
      uVar4 = uVar2 - 0x30;
    }
  }
  if (((1 << (uVar4 & 0x1f) & uVar3) >> (uVar4 & 0x1f) & 0xff) == 0) {
    if (0x37 < uVar2) {
_L171:
      r_assert_err(0,0x10000,0x27c8);
    }
    if (0x2f < (int)uVar2) {
_L172:
      iVar1 = 0x488;
      goto _L183;
    }
  }
  else {
    if (0x37 < uVar2) {
      r_assert_err(0,0x10000,0x27fa);
    }
    if (0x1f < (int)uVar2) {
      if ((int)uVar2 < 0x30) {
        puVar5 = (uint *)&DAT_600312c8;
        uVar3 = uVar2 - 0x20;
        uVar4 = _DAT_600312c8;
        goto _L184;
      }
      _DAT_60031300 = ~(1 << (uVar2 - 0x30 & 0x1f)) & _DAT_60031300;
      if (0x37 < uVar2) goto _L171;
      goto _L172;
    }
    puVar5 = (uint *)&DAT_600312c4;
    uVar4 = _DAT_600312c4;
    uVar3 = uVar2;
_L184:
    *puVar5 = ~(1 << (uVar3 & 0x1f)) & uVar4;
    if (0x37 < uVar2) goto _L171;
  }
  iVar1 = 0x481;
_L183:
  puVar5 = (uint *)((iVar1 + 0x1800c000 + uVar2) * 4);
  if ((*puVar5 & 0x3ffff) != 0) {
    if (0x37 < uVar2) {
      r_assert_err(0,0x10000,0x27c8);
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))
              ((*puVar5 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
    if (0x37 < uVar2) {
      r_assert_err(0,0x10000,0x27c1);
    }
    *puVar5 = *puVar5 & 0xfffc0000;
  }
  return;
}

