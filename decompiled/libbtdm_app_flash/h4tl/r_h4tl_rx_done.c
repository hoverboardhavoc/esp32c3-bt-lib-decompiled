/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_rx_done(undefined4 *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    bVar1 = *(byte *)(param_1 + 5);
    if (bVar1 == 2) {
      cVar2 = *(char *)((int)param_1 + 0x15);
      if (cVar2 == '\x02') {
        r_hci_acl_tx_data_received
                  (*(undefined2 *)((int)param_1 + 10),*(undefined2 *)(param_1 + 3),
                   *(undefined2 *)(param_1 + 2));
        goto _L84;
      }
      if (cVar2 != '\x05') {
        uVar6 = 0x3ca;
        if (cVar2 != '\x01') {
_L88:
          r_assert_param(*(undefined1 *)((int)param_1 + 0x16),0x10000,uVar6);
          return;
        }
        uVar6 = 10;
        goto _L87;
      }
      iVar4 = param_1[1];
    }
    else {
      if (2 < bVar1) {
        if (bVar1 != 3) {
          r_assert_err(0,0x10000,999);
          return;
        }
        iVar4 = r_h4tl_out_of_sync_check();
        if (iVar4 == 0) {
          *(undefined1 *)(param_1 + 5) = 3;
                    /* WARNING: Could not recover jumptable at 0x000101f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
          return;
        }
        goto _L84;
      }
      if (bVar1 == 0) {
        uVar7 = (uint)*(byte *)((int)param_1 + 0x13);
        *(byte *)((int)param_1 + 0x15) = *(byte *)((int)param_1 + 0x13);
        if (uVar7 != 4) {
          if (4 < uVar7) {
            uVar5 = 8;
            if (uVar7 != 5) goto _L67;
            goto _L85;
          }
          if (1 < (uVar7 - 1 & 0xff)) {
_L67:
            puVar3 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x10,1);
            *puVar3 = 0;
            r_hci_send_2_host();
            memset((void *)((int)param_1 + 10),0,8);
            *(undefined1 *)((int)param_1 + 0x12) = *(undefined1 *)((int)param_1 + 0x13);
            r_h4tl_read_next_out_of_sync(param_1);
            r_rwip_prevent_sleep_clear(4);
            return;
          }
        }
        uVar5 = *(undefined1 *)((int)&h4tl_msgtype2hdrlen + uVar7);
_L85:
        *(undefined1 *)(param_1 + 5) = 1;
        (**(code **)*param_1)((int)param_1 + 10,uVar5,r_h4tl_rx_done,param_1,*(code **)*param_1);
        r_rwip_prevent_sleep_set(4);
        return;
      }
      cVar2 = *(char *)((int)param_1 + 0x15);
      if (cVar2 == '\x02') {
        uVar6 = 0xb;
_L87:
        r_ke_event_set(uVar6);
        return;
      }
      if (cVar2 != '\x05') {
        uVar6 = 0x353;
        if (cVar2 != '\x01') goto _L88;
        uVar6 = 9;
        goto _L87;
      }
      uVar7 = (**(code **)(_r_hli_funcs_p + 0x10))
                        (*(undefined2 *)(param_1 + 3),*(code **)(_r_hli_funcs_p + 0x10));
      if ((uVar7 & 0xff) == 0xff) {
        iVar4 = r_ke_msg_alloc(0xdaf,8,*(undefined2 *)(param_1 + 3),*(undefined2 *)(param_1 + 4));
        *(undefined2 *)(iVar4 + -2) = *(undefined2 *)((int)param_1 + 10);
      }
      else {
        uVar6 = (**(code **)(_r_hli_funcs_p + 0x10))
                          (*(undefined2 *)((int)param_1 + 0xe),*(code **)(_r_hli_funcs_p + 0x10));
        *(short *)((int)param_1 + 0xe) = (short)uVar6;
        iVar4 = r_ke_msg_alloc(*(undefined2 *)((int)param_1 + 10),uVar7,uVar6,
                               *(undefined2 *)(param_1 + 4));
      }
      if (*(short *)(param_1 + 4) != 0) {
        param_1[1] = iVar4;
        *(undefined2 *)(param_1 + 2) = 0;
        *(undefined1 *)(param_1 + 5) = 2;
                    /* WARNING: Could not recover jumptable at 0x000101de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)*param_1)(param_1[1],r_h4tl_rx_done,param_1,*(code **)*param_1);
        return;
      }
    }
    r_ke_msg_send(iVar4);
  }
  else if ((param_2 == 1) || (*(char *)(param_1 + 5) != '\0')) goto _L67;
_L84:
  *(undefined1 *)(param_1 + 5) = 0;
  (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
  r_rwip_prevent_sleep_clear(4);
  return;
}

