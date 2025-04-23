/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_all_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_all_release(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    iVar3 = r_sdk_config_get_opts();
    if ((int)(uint)*(byte *)(iVar3 + 0xd) <= (int)uVar2) {
      return;
    }
    bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
    if (bVar1 < 4) {
      if (bVar1 != 0) {
_L840:
        r_llm_adv_set_release_hack(uVar2 & 0xff);
      }
    }
    else if ((byte)(bVar1 - 10) < 4) goto _L840;
    uVar2 = uVar2 + 1;
  } while( true );
}

