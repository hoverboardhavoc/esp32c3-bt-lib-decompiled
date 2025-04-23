/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_overwrite_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_overwrite_em_mapping_by_offset(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar2 = (**(code **)(_r_osi_funcs_p + 0x78))(param_2,*(code **)(_r_osi_funcs_p + 0x78));
  if (iVar2 == 0) {
    return 7;
  }
  uVar3 = r_emi_get_em_mapping_idx_by_offset(param_1);
  if ((int)uVar3 < 0x38) {
    if (0x2f < (int)uVar3) goto _L110;
    iVar1 = 0x481;
  }
  else {
    r_assert_err(0,0x10000,0x27c1);
_L110:
    iVar1 = 0x488;
  }
  puVar4 = (uint *)((iVar1 + 0x1800c000 + uVar3) * 4);
  *puVar4 = *puVar4 & 0xfffc0000 | (uint)(iVar2 << 0xc) >> 0xe;
  if ((int)uVar3 < 0x38) {
    if (0x1f < (int)uVar3) {
      if ((int)uVar3 < 0x30) {
        puVar4 = (uint *)&DAT_600312c8;
        uVar3 = 1 << (uVar3 - 0x20 & 0x1f);
        uVar3 = ~uVar3 & _DAT_600312c8 | uVar3;
        goto _L119;
      }
      goto _L113;
    }
    iVar2 = 0x2c4;
  }
  else {
    r_assert_err(0,0x10000,0x27fa);
_L113:
    uVar3 = uVar3 - 0x30;
    iVar2 = 0x300;
  }
  puVar4 = (uint *)(iVar2 + 0x60031000);
  uVar3 = 1 << (uVar3 & 0x1f);
  uVar3 = ~uVar3 & *puVar4 | uVar3;
_L119:
  *puVar4 = uVar3;
  return 0;
}

