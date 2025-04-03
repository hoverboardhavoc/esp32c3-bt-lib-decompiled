/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_activity_free_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_activity_free_get(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  *param_1 = 0;
  do {
    bVar1 = *param_1;
    iVar3 = r_sdk_config_get_opts();
    iVar5 = _p_llm_env;
    if (*(byte *)(iVar3 + 0xd) <= bVar1) {
_L410:
      bVar1 = *param_1;
      iVar5 = r_sdk_config_get_opts();
      uVar4 = 0;
      if (*(byte *)(iVar5 + 0xd) <= bVar1) {
        uVar4 = 7;
      }
      return uVar4;
    }
    iVar3 = *(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44;
    if (*(char *)(iVar3 + 0x40) == '\0') {
      memset((void *)(iVar3 + 0x28),0,0x18);
      iVar5 = *(int *)(iVar5 + 8);
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar5 + 0x30) = 0x672;
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar5 + 0x3a) = 0x672;
      *(undefined2 *)(iVar5 + (uint)*param_1 * 0x44 + 0x30) = 0x672;
      uVar2 = (uint)*param_1;
      *(undefined4 *)((uVar2 + 0x1800c4cb) * 4) = 0;
      r_bt_rma_deregister_rule_cs_idx(uVar2);
      r_bt_rtp_deregister_rule_cs_idx(uVar2);
      goto _L410;
    }
    *param_1 = *param_1 + 1;
  } while( true );
}

