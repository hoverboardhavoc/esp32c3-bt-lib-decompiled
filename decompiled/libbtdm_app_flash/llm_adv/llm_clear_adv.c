/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint uVar4;
  
  uVar1 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar2 = r_llm_adv_hdl_to_id(0xff,0);
    iVar3 = r_sdk_config_get_opts();
    uVar1 = 0;
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      uVar4 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
      if (uVar4 == 1) {
        r_llm_adv_set_release_hack(uVar2);
      }
      else {
        r_ble_log_internal_x1(0x802e01b5,uVar2 << 8 | uVar4 << 0x10 | 0xc);
        uVar1 = 0xc;
      }
    }
  }
  return uVar1;
}

