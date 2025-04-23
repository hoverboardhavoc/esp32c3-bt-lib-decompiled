/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> llm_clear_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_clear_adv(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L822:
    uVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar2 = r_llm_adv_hdl_to_id(0xff,0);
    iVar3 = r_sdk_config_get_opts();
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      if (*(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40) != '\x01') goto _L822;
      r_llm_adv_set_release_hack(uVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

