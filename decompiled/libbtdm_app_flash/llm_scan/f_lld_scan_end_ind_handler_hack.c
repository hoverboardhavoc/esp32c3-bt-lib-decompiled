/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_scan_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_scan_end_ind_handler_hack(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  
  uVar3 = (uint)*(byte *)(param_1 + 1);
  iVar2 = uVar3 * 0x44;
  iVar6 = *(int *)(_p_llm_env + 8) + iVar2;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      r_assert_err(0,"llm_scan.c",0x86d);
      goto _L893;
    }
    r_llm_cmd_cmp_send(0x200c,0);
    uVar4 = 0x404e01ed;
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 6;
  }
  else {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      if (*(ushort *)(iVar6 + 0x2a) == 0) {
        puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,1);
        *puVar5 = 0x11;
        r_hci_send_2_host();
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 6;
        r_ble_log_internal_x1(0x404e01ef,uVar3 | 0x600);
      }
      else {
        r_ke_timer_set(3,0,(uint)*(ushort *)(iVar6 + 0x2a) * 0x80 - (uint)*(ushort *)(iVar6 + 0x28))
        ;
      }
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar3,3,0);
      }
      goto _L893;
    }
    r_llm_cmd_cmp_send(0x2042,0);
    uVar4 = 0x404e01ee;
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 6;
  }
  r_ble_log_internal_x1(uVar4,uVar3 | 0x600);
_L893:
  iVar6 = _p_llm_env;
  cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40);
  if ((cVar1 == '\x06') || ((*(byte *)(_p_llm_env + 0xd4) & 2) != 0)) {
    *(undefined1 *)(_p_llm_env + 0xd2) = 0;
    *(undefined1 *)(iVar6 + 0xd1) = 0;
    if (cVar1 == '\x06') {
      r_llm_env_adv_dup_filt_deinit_eco();
    }
    r_ble_log_internal_x1
              (0x40c101f0,
               (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) << 8 |
               (uint)*(byte *)(_p_llm_env + 0xd4) << 0x10 |
               (uint)*(byte *)(_p_llm_env + 0xd2) << 0x18 | uVar3);
  }
  return 0;
}

