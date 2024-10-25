/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_tl_hci_pkt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_hci_pkt_handler(void)

{
  char *pcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *__dest;
  undefined2 uVar5;
  
  pcVar1 = _hci_tl_env;
  if (*_hci_tl_env == '\x01') {
    uVar3 = 6;
    if (_hci_tl_env[3] != '\0') {
      uVar3 = 7;
    }
    r_ke_event_set(uVar3);
    return;
  }
  if (*_hci_tl_env == '\x02') {
    uVar2 = *(undefined2 *)(_hci_tl_env + 1);
    if (*(short *)(_hci_tl_env + 3) == 0) {
      iVar4 = 0;
      uVar5 = 0;
    }
    else {
      iVar4 = r_hci_acl_tx_data_alloc(uVar2);
      if ((iVar4 == 0) || (__dest = (void *)r_emi_get_mem_addr_by_offset(), __dest == (void *)0x0))
      {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("HCITL: fail to alloc acl %0x, %0x\n",iVar4,0);
        }
        goto _L227;
      }
      memcpy(__dest,pcVar1 + 5,(uint)*(ushort *)(pcVar1 + 3));
      uVar5 = *(undefined2 *)(pcVar1 + 3);
      uVar2 = *(undefined2 *)(pcVar1 + 1);
    }
    r_hci_acl_tx_data_received(uVar2,uVar5,iVar4);
  }
_L227:
  r_vhci_notify_host_send_available();
  return;
}

