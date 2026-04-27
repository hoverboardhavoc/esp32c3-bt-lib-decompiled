/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_legacy_adv_dynamic_pti_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_legacy_adv_dynamic_pti_get(int param_1,undefined1 *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  uVar2 = *(uint *)(param_1 + 100);
  puVar4 = *(undefined1 **)(_bt_rf_coex_cfg_p + 0x2c);
  if (*(ushort *)(puVar4 + 10) < uVar2) {
    if (*(ushort *)(puVar4 + 0xc) < uVar2) {
_L114:
      bVar1 = puVar4[9];
    }
    else {
      bVar1 = puVar4[8];
    }
    if ((uint)*(byte *)(param_1 + 0x86) % (uint)bVar1 != 0) {
_L115:
      uVar3 = puVar4[6];
      goto _L116;
    }
  }
  else if ((uint)*(byte *)(param_1 + 0x86) % (uint)(byte)puVar4[7] != 0) {
    if (*(ushort *)(puVar4 + 0xc) < uVar2) goto _L114;
    goto _L115;
  }
  *param_2 = *puVar4;
  param_2[1] = puVar4[1];
  param_2[2] = puVar4[2];
  param_2[3] = puVar4[3];
  param_2[4] = puVar4[4];
  uVar3 = puVar4[5];
_L116:
  param_2[5] = uVar3;
  return;
}

