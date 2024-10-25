/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_rx_done(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    if ((param_2 == 1) || (*(char *)(param_1 + 5) != '\0')) goto _L71;
    goto _L87;
  }
  cVar1 = *(char *)(param_1 + 5);
  if (cVar1 == '\x01') {
    cVar1 = *(char *)((int)param_1 + 0x15);
    if (cVar1 == '\x02') {
      uVar5 = 0xb;
_L90:
      r_ke_event_set(uVar5);
      return;
    }
    if (cVar1 != '\x05') {
      uVar5 = 0x353;
      if (cVar1 != '\x01') {
_L91:
        r_assert_param(*(undefined1 *)((int)param_1 + 0x16),"h4tl.c",uVar5);
        return;
      }
      uVar5 = 9;
      goto _L90;
    }
    uVar6 = (**(code **)(_r_hli_funcs_p + 0x10))
                      (*(undefined2 *)(param_1 + 3),*(code **)(_r_hli_funcs_p + 0x10));
    if ((uVar6 & 0xff) == 0xff) {
      iVar3 = r_ke_msg_alloc(0xdaf,8,*(undefined2 *)(param_1 + 3),*(undefined2 *)(param_1 + 4));
      *(undefined2 *)(iVar3 + -2) = *(undefined2 *)((int)param_1 + 10);
    }
    else {
      uVar5 = (**(code **)(_r_hli_funcs_p + 0x10))
                        (*(undefined2 *)((int)param_1 + 0xe),*(code **)(_r_hli_funcs_p + 0x10));
      *(short *)((int)param_1 + 0xe) = (short)uVar5;
      iVar3 = r_ke_msg_alloc(*(undefined2 *)((int)param_1 + 10),uVar6,uVar5,
                             *(undefined2 *)(param_1 + 4));
    }
    if (*(short *)(param_1 + 4) != 0) {
      param_1[1] = iVar3;
      *(undefined2 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 5) = 2;
                    /* WARNING: Could not recover jumptable at 0x000101cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*param_1)(param_1[1],r_h4tl_rx_done,param_1);
      return;
    }
  }
  else {
    if (cVar1 == '\0') {
      uVar6 = (uint)*(byte *)((int)param_1 + 0x13);
      *(byte *)((int)param_1 + 0x15) = *(byte *)((int)param_1 + 0x13);
      if (uVar6 != 4) {
        if (4 < uVar6) {
          uVar4 = 8;
          if (uVar6 != 5) goto _L71;
          goto _L88;
        }
        if (1 < (uVar6 - 1 & 0xff)) {
_L71:
          puVar2 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x10,1);
          *puVar2 = 0;
          r_hci_send_2_host();
          memset((void *)((int)param_1 + 10),0,8);
          *(undefined1 *)((int)param_1 + 0x12) = *(undefined1 *)((int)param_1 + 0x13);
          r_h4tl_read_next_out_of_sync(param_1);
          r_rwip_prevent_sleep_clear(4);
          return;
        }
      }
      uVar4 = *(undefined1 *)((int)&h4tl_msgtype2hdrlen + uVar6);
_L88:
      *(undefined1 *)(param_1 + 5) = 1;
      (**(code **)*param_1)((int)param_1 + 10,uVar4,r_h4tl_rx_done,param_1,*(code **)*param_1);
      r_rwip_prevent_sleep_set(4);
      return;
    }
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        r_assert_err(0,"h4tl.c",999);
        return;
      }
      iVar3 = r_h4tl_out_of_sync_check();
      if (iVar3 == 0) {
        *(undefined1 *)(param_1 + 5) = 3;
                    /* WARNING: Could not recover jumptable at 0x000101e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1);
        return;
      }
      goto _L87;
    }
    cVar1 = *(char *)((int)param_1 + 0x15);
    if (cVar1 == '\x02') {
      r_hci_acl_tx_data_received
                (*(undefined2 *)((int)param_1 + 10),*(undefined2 *)(param_1 + 3),
                 *(undefined2 *)(param_1 + 2));
      goto _L87;
    }
    if (cVar1 != '\x05') {
      uVar5 = 0x3ca;
      if (cVar1 != '\x01') goto _L91;
      uVar5 = 10;
      goto _L90;
    }
    iVar3 = param_1[1];
  }
  r_ke_msg_send(iVar3);
_L87:
  *(undefined1 *)(param_1 + 5) = 0;
  (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
  r_rwip_prevent_sleep_clear(4);
  return;
}

