/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_activity_free_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_activity_free_get(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  do {
    *param_1 = (byte)uVar2;
    iVar3 = r_sdk_config_get_opts();
    iVar4 = _p_llm_env;
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
_L443:
      bVar1 = *param_1;
      iVar4 = r_sdk_config_get_opts();
      uVar2 = 0;
      if (*(byte *)(iVar4 + 0xd) <= bVar1) {
        uVar2 = 7;
      }
      r_ble_log_internal_x1(0x404e0175,(uint)*param_1 << 8 | uVar2);
      return uVar2;
    }
    iVar3 = *(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44;
    if (*(char *)(iVar3 + 0x40) == '\0') {
      memset((void *)(iVar3 + 0x28),0,0x18);
      iVar4 = *(int *)(iVar4 + 8);
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar4 + 0x30) = 0x672;
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar4 + 0x3a) = 0x672;
      *(undefined2 *)(iVar4 + (uint)*param_1 * 0x44 + 0x30) = 0x672;
      uVar2 = (uint)*param_1;
      *(undefined4 *)((uVar2 + 0x1800c4cb) * 4) = 0;
      r_bt_rma_deregister_rule_cs_idx(uVar2);
      r_bt_rtp_deregister_rule_cs_idx(uVar2);
      goto _L443;
    }
    uVar2 = *param_1 + 1 & 0xff;
  } while( true );
}

