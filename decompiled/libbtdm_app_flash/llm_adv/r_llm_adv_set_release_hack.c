/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_release_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_release_hack(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  memset((void *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44 + 4),0,6);
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 4) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40000003,param_1);
  }
  iVar2 = param_1 * 0x44;
  piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
  if ((short)piVar4[10] != 0) {
    r_ble_util_buf_adv_tx_free();
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    piVar4[10] = 0;
  }
  if ((short)piVar4[0xb] != 0) {
    r_ble_util_buf_adv_tx_free();
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    piVar4[0xb] = 0;
  }
  if (*(short *)((int)piVar4 + 0x32) != 0) {
    r_ble_util_buf_adv_tx_free();
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *(undefined2 *)((int)piVar4 + 0x32) = 0;
    *(undefined2 *)(piVar4 + 0xd) = 0;
  }
  if (*(short *)((int)piVar4 + 0x36) != 0) {
    r_ble_util_buf_adv_tx_free();
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *(undefined2 *)((int)piVar4 + 0x36) = 0;
    *(undefined2 *)(piVar4 + 0xe) = 0;
  }
  if (*piVar4 != 0) {
    r_ke_msg_free(*piVar4 + -0xc);
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *piVar4 = 0;
  }
  bVar1 = *(byte *)((int)piVar4 + 0x3d);
  iVar3 = r_sdk_config_get_opts();
  if (bVar1 < *(byte *)(iVar3 + 0xd)) {
    uVar5 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
    iVar3 = uVar5 * 0x44;
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
    if ((short)piVar4[10] != 0) {
      r_ble_util_buf_adv_tx_free();
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      piVar4[10] = 0;
    }
    if ((short)piVar4[0xb] != 0) {
      r_ble_util_buf_adv_tx_free();
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      piVar4[0xb] = 0;
    }
    if (*piVar4 != 0) {
      r_ke_msg_free(*piVar4 + -0xc);
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      *piVar4 = 0;
    }
    *(undefined1 *)(piVar4 + 0x10) = 0;
    r_bt_rtp_deregister_rule_cs_idx(uVar5);
    r_bt_rma_deregister_rule_cs_idx(uVar5);
  }
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 0;
  r_bt_rtp_deregister_rule_cs_idx(param_1);
  r_bt_rma_deregister_rule_cs_idx(param_1);
  return;
}

