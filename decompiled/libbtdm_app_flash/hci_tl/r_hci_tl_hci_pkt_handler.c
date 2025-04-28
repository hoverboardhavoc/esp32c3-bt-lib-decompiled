/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  pcVar1 = _memcpy;
  if (*_memcpy == '\x01') {
    uVar3 = 6;
    if (_memcpy[3] != '\0') {
      uVar3 = 7;
    }
    r_ke_event_set(uVar3);
    return;
  }
  if (*_memcpy == '\x02') {
    uVar2 = *(undefined2 *)(_memcpy + 1);
    if (*(short *)(_memcpy + 3) == 0) {
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
        goto _L222;
      }
      memcpy(__dest,pcVar1 + 5,(uint)*(ushort *)(pcVar1 + 3));
      uVar5 = *(undefined2 *)(pcVar1 + 3);
      uVar2 = *(undefined2 *)(pcVar1 + 1);
    }
    r_hci_acl_tx_data_received(uVar2,uVar5,iVar4);
  }
_L222:
  r_vhci_notify_host_send_available();
  return;
}

