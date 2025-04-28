/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> llm_is_non_con_legacy_act_ongoing_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_is_non_con_legacy_act_ongoing_check(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  while( true ) {
    iVar3 = r_sdk_config_get_opts();
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
      return 0;
    }
    bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
    if ((((*(char *)(_p_llm_env + 0xd7) == '\x01') && ((byte)(bVar1 - 2) < 2)) || (bVar1 == 0xe)) ||
       ((bVar1 & 0xfd) == 5)) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return 1;
}

