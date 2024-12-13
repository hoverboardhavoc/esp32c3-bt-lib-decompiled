/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_scan_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_scan_end_ind_handler_hack(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = (uint)bVar1 * 0x44;
  iVar6 = *(int *)(_p_llm_env + 8) + iVar3;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      r_assert_err(0,"llm_scan.c",0x81f);
      goto _L894;
    }
    uVar4 = 0x200c;
  }
  else {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      if (*(ushort *)(iVar6 + 0x2a) == 0) {
        puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,1);
        *puVar5 = 0x11;
        r_hci_send_2_host();
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 6;
      }
      else {
        r_ke_timer_set(3,0,(uint)*(ushort *)(iVar6 + 0x2a) * 0x80 - (uint)*(ushort *)(iVar6 + 0x28))
        ;
      }
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)((uint)bVar1,3,0);
      }
      goto _L894;
    }
    uVar4 = 0x2042;
  }
  r_llm_cmd_cmp_send(uVar4,0);
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 6;
_L894:
  iVar6 = _p_llm_env;
  cVar2 = *(char *)(iVar3 + *(int *)(_p_llm_env + 8) + 0x40);
  if ((cVar2 == '\x06') || ((*(byte *)(_p_llm_env + 0xd4) & 2) != 0)) {
    *(undefined1 *)(_p_llm_env + 0xd2) = 0;
    *(undefined1 *)(iVar6 + 0xd1) = 0;
    if (cVar2 == '\x06') {
      r_llm_env_adv_dup_filt_deinit_eco();
    }
  }
  return 0;
}

