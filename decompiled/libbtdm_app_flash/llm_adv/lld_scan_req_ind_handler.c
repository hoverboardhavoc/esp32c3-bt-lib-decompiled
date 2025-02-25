/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llm_adv.o -> lld_scan_req_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_scan_req_ind_handler(byte *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44);
  puVar3 = (undefined1 *)*puVar2;
  if (1 < (byte)(*(char *)(puVar2 + 0x10) - 2U)) {
    r_assert_param("llm_adv.c",0xcad);
  }
  if (puVar3[0x19] != '\0') {
    puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,9);
    *puVar1 = 0x13;
    puVar1[1] = *puVar3;
    puVar1[2] = param_1[1];
    memcpy(puVar1 + 3,param_1 + 2,6);
    r_hci_send_2_host(puVar1);
  }
  return 0;
}

