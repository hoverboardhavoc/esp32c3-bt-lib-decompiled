/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    bVar1 = *(byte *)(param_1 + 5);
    if (bVar1 == 2) {
      cVar2 = *(char *)((int)param_1 + 0x15);
      if (cVar2 == '\x02') {
        r_hci_acl_tx_data_received
                  (*(undefined2 *)((int)param_1 + 10),*(undefined2 *)(param_1 + 3),
                   *(undefined2 *)(param_1 + 2));
        goto _L93;
      }
      if (cVar2 != '\x05') {
        if (cVar2 != '\x01') {
          uVar4 = 0x3ca;
_L97:
          r_assert_param(*(undefined1 *)((int)param_1 + 0x16),0x10000,uVar4);
          return;
        }
        uVar4 = 10;
        goto _L96;
      }
      iVar5 = param_1[1];
    }
    else {
      if (2 < bVar1) {
        if (bVar1 != 3) {
          r_assert_err(0,0x10000,999);
          return;
        }
        iVar5 = r_h4tl_out_of_sync_check();
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 5) = 3;
                    /* WARNING: Could not recover jumptable at 0x00010218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
          return;
        }
        goto _L93;
      }
      if (bVar1 == 0) {
        uVar7 = (uint)*(byte *)((int)param_1 + 0x13);
        *(byte *)((int)param_1 + 0x15) = *(byte *)((int)param_1 + 0x13);
        if (uVar7 != 4) {
          if (4 < uVar7) {
            uVar6 = 8;
            if (uVar7 != 5) goto _L76;
            goto _L94;
          }
          if (1 < (uVar7 - 1 & 0xff)) {
_L76:
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
        uVar6 = *(undefined1 *)((int)&h4tl_msgtype2hdrlen + uVar7);
_L94:
        *(undefined1 *)(param_1 + 5) = 1;
        (**(code **)*param_1)((int)param_1 + 10,uVar6,r_h4tl_rx_done,param_1,*(code **)*param_1);
        r_rwip_prevent_sleep_set(4);
        return;
      }
      cVar2 = *(char *)((int)param_1 + 0x15);
      if (cVar2 == '\x02') {
        uVar4 = 0xb;
_L96:
        r_ke_event_set(uVar4);
        return;
      }
      if (cVar2 != '\x05') {
        if (cVar2 != '\x01') {
          uVar4 = 0x353;
          goto _L97;
        }
        uVar4 = 9;
        goto _L96;
      }
      uVar7 = (**(code **)(_r_hli_funcs_p + 0x10))
                        (*(undefined2 *)(param_1 + 3),*(code **)(_r_hli_funcs_p + 0x10));
      if ((uVar7 & 0xff) == 0xff) {
        iVar5 = r_ke_msg_alloc(0xdaf,8,*(undefined2 *)(param_1 + 3),*(undefined2 *)(param_1 + 4));
        *(undefined2 *)(iVar5 + -2) = *(undefined2 *)((int)param_1 + 10);
      }
      else {
        uVar4 = (**(code **)(_r_hli_funcs_p + 0x10))
                          (*(undefined2 *)((int)param_1 + 0xe),*(code **)(_r_hli_funcs_p + 0x10));
        *(short *)((int)param_1 + 0xe) = (short)uVar4;
        iVar5 = r_ke_msg_alloc(*(undefined2 *)((int)param_1 + 10),uVar7,uVar4,
                               *(undefined2 *)(param_1 + 4));
      }
      if (*(short *)(param_1 + 4) != 0) {
        param_1[1] = iVar5;
        *(undefined2 *)(param_1 + 2) = 0;
        *(undefined1 *)(param_1 + 5) = 2;
                    /* WARNING: Could not recover jumptable at 0x000101fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)*param_1)(param_1[1],r_h4tl_rx_done,param_1,*(code **)*param_1);
        return;
      }
    }
    r_ke_msg_send(iVar5);
  }
  else if ((param_2 == 1) || (*(char *)(param_1 + 5) != '\0')) goto _L76;
_L93:
  *(undefined1 *)(param_1 + 5) = 0;
  (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
  r_rwip_prevent_sleep_clear(4);
  return;
}

