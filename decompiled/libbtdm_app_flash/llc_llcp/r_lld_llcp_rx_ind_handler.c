/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_lld_llcp_rx_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_llcp_rx_ind_handler(undefined2 *param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte local_50 [48];
  
  uVar7 = param_2 >> 8;
  iVar6 = *(int *)(&llc_env + uVar7 * 4);
  uVar1 = uVar7 & 0xff;
  if (iVar6 == 0) {
    r_assert_param(uVar7,0,"llc_llcp.c",0xfd);
    goto _L85;
  }
  if ((*(ushort *)(iVar6 + 0x42) & 0x40) != 0) goto _L85;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  local_50[0] = abStack_6c[0];
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 0x20) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 2)) {
    r_ble_log_internal_hex(0x20c3001d,*(undefined1 *)(param_1 + 1),abStack_6c);
  }
  uVar4 = (uint)local_50[0];
  if (uVar4 < 0x23) {
    if (*(ushort *)(&DAT_00010850 + uVar4 * 0xc) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_6e = 0x30;
      iVar3 = r_co_util_unpack(local_50,abStack_6c,&uStack_6e,(&PTR__LC1_0001084c)[uVar4 * 3]);
      if (iVar3 != 0) {
        iVar3 = 0x1e;
      }
      uVar4 = (uint)local_50[0];
      bVar5 = *(byte *)(iVar6 + 0x44) & 3;
      if (bVar5 != 2) {
        if (bVar5 == 3) {
          bVar5 = (&DAT_00010852)[uVar4 * 0xc] & 8;
        }
        else {
          if (bVar5 == 1) {
            if (((&DAT_00010852)[uVar4 * 0xc] & 4) == 0) goto _L128;
            goto _L99;
          }
          bVar5 = (&DAT_00010852)[uVar4 * 0xc] & 1;
        }
        if (bVar5 == 0) goto _L85;
      }
_L99:
      if (iVar3 == 0) {
        if (0x22 < uVar4) {
          r_assert_param(param_2,"llc_llcp.c",0x18b);
        }
        iVar3 = r_llc_llcp_pdu_handler_pre(uVar1,local_50,*param_1);
        if ((iVar3 == 0) &&
           (pcVar2 = (code *)r_llc_llcp_pdu_handler_get_overwrite(local_50[0]),
           pcVar2 != (code *)0x0)) {
          iVar3 = (*pcVar2)(uVar1,local_50,*param_1,pcVar2);
        }
        if ((local_50[0] == 6) && (iVar3 == 0)) {
          if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
            llc_enc_state = (ushort)(1 << (uVar7 & 0x1f)) | llc_enc_state;
          }
          goto _L85;
        }
        if ((iVar3 == 0x28) || (iVar3 == 0x3d)) goto _L129;
        if (iVar3 == 0) goto _L85;
      }
      r_llc_ll_reject_ind_pdu_send(uVar1,local_50[0],iVar3,0);
      goto _L85;
    }
  }
  else {
    bVar5 = *(byte *)(iVar6 + 0x44) & 3;
    if ((*(byte *)(iVar6 + 0x44) & 3) != 0) {
      if (bVar5 < 3) {
_L128:
        iVar3 = 0x3d;
_L129:
        r_llc_disconnect(uVar1,iVar3,1);
        goto _L85;
      }
      if (bVar5 == 3) goto _L85;
    }
  }
  llc_ll_unknown_rsp_pdu_send(uVar1);
_L85:
  r_ble_util_buf_rx_free(param_1[2],*(undefined4 *)(param_1 + 4));
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x20) != '\0') {
    r_llc_le_ping_restart(uVar1);
  }
  return 0;
}

