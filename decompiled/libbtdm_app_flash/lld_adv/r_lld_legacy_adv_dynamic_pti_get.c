/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
_L112:
      bVar1 = puVar4[9];
    }
    else {
      bVar1 = puVar4[8];
    }
    if ((uint)*(byte *)(param_1 + 0x86) % (uint)bVar1 != 0) {
_L113:
      uVar3 = puVar4[6];
      goto _L114;
    }
  }
  else if ((uint)*(byte *)(param_1 + 0x86) % (uint)(byte)puVar4[7] != 0) {
    if (*(ushort *)(puVar4 + 0xc) < uVar2) goto _L112;
    goto _L113;
  }
  *param_2 = *puVar4;
  param_2[1] = puVar4[1];
  param_2[2] = puVar4[2];
  param_2[3] = puVar4[3];
  param_2[4] = puVar4[4];
  uVar3 = puVar4[5];
_L114:
  param_2[5] = uVar3;
  return;
}

