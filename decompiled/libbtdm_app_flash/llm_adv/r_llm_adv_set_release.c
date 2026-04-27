/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_release(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = param_1 * 0x44;
  r_ble_log_internal_x1(0x404e01c1,param_1);
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28) != 0) {
    r_ble_util_buf_adv_tx_free();
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) != 0) {
    r_ble_util_buf_adv_tx_free();
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x32) != 0) {
    r_ble_util_buf_adv_tx_free();
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2;
    *(undefined2 *)(iVar4 + 0x32) = 0;
    *(undefined2 *)(iVar4 + 0x34) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x36) != 0) {
    r_ble_util_buf_adv_tx_free();
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2;
    *(undefined2 *)(iVar4 + 0x36) = 0;
    *(undefined2 *)(iVar4 + 0x38) = 0;
  }
  iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + iVar2);
  if (iVar4 != 0) {
    r_ke_msg_free(iVar4 + -0xc);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2) = 0;
  }
  bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
  iVar4 = r_sdk_config_get_opts();
  if (bVar1 < *(byte *)(iVar4 + 0xd)) {
    bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
    uVar5 = (uint)bVar1;
    iVar4 = uVar5 * 0x44;
    if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) != 0) {
      r_ble_util_buf_adv_tx_free();
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) = 0;
    }
    if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2c) != 0) {
      r_ble_util_buf_adv_tx_free();
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2c) = 0;
    }
    iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + iVar4);
    if (iVar3 != 0) {
      r_ke_msg_free(iVar3 + -0xc);
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4) = 0;
    }
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40) = 0;
    r_bt_rtp_deregister_rule_cs_idx(uVar5);
    r_bt_rma_deregister_rule_cs_idx(uVar5);
    r_ble_log_internal_x1
              (0x404e01c2,CONCAT11(*(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40),bVar1));
  }
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 0;
  r_bt_rtp_deregister_rule_cs_idx(param_1);
  r_bt_rma_deregister_rule_cs_idx(param_1);
  r_ble_log_internal_x1
            (0x404e01c3,(uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) << 8 | param_1);
  return;
}

