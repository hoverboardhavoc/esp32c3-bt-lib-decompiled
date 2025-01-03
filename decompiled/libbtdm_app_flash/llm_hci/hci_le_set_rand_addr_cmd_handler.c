/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_rand_addr_cmd_handler(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = llm_is_non_con_legacy_act_ongoing_check();
  uVar2 = 0xc;
  if (iVar1 == 0) {
    iVar1 = r_co_bdaddr_compare(param_1,&co_null_bdaddr);
    uVar2 = 0x12;
    if (iVar1 == 0) {
      memcpy((void *)(_p_llm_env + 0x12),param_1,6);
      uVar2 = 0;
    }
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

