/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send_eco(uint param_1,byte *param_2,code *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort uStack_22;
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40e30015,(uint)*param_2 << 8 | param_1);
  }
  bVar1 = *param_2;
  if (bVar1 == 0) {
    param_3 = llc_llcp_conn_update_ind_ack;
  }
  else if (bVar1 == 1) {
    param_3 = r_llc_llcp_channel_map_ind_ack;
  }
  else if (bVar1 == 0x18) {
    iVar5 = r_sdk_config_get_opts_ext();
    param_3 = llc_llcp_phy_update_ind_ack;
    if (*(char *)(iVar5 + 0x18) == '\0') {
      r_assert_err(0,"llc_llcp.c",0x1e9);
    }
  }
  else if (bVar1 == 6) {
    DAT_000108ee = (ushort)(1 << (param_1 & 0x1f)) | DAT_000108ee;
  }
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == (byte *)0x0) {
    uVar6 = 0xffff;
  }
  else {
    uVar6 = (uint)*param_2;
    if ((iVar5 != 0) && (uVar6 < 0x23)) {
      uStack_22 = *(ushort *)(llcp_pdu_handler + uVar6 * 0xc + 8);
      iVar2 = r_ke_malloc(uStack_22 + 0xc,2);
      bVar1 = *param_2;
      *(code **)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,&uStack_22,0x30,
                             *(undefined4 *)(llcp_pdu_handler + (uint)bVar1 * 0xc + 4));
      if (iVar3 != 0) {
        r_assert_param(*param_2,"llc_llcp.c",0x32f);
      }
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x20) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 2)) {
        r_ble_log_internal_hex(0x20e30016,uStack_22,iVar2 + 9);
      }
      if (iVar3 == 0) {
        *(char *)(iVar2 + 8) = (char)uStack_22;
        r_co_list_push_back(iVar5 + 0x28,iVar2);
        r_llc_llcp_tx_check_hack(param_1);
      }
      return;
    }
  }
  r_assert_param(param_1,uVar6,"llc_llcp.c",0x33e);
  return;
}

