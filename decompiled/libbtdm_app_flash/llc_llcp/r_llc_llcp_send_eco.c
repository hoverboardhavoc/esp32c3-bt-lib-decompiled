/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send_eco(int param_1,byte *param_2,code *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort auStack_22 [3];
  
  bVar1 = *param_2;
  if (bVar1 == 0) {
    param_3 = llc_llcp_conn_update_ind_ack;
  }
  else if (bVar1 == 1) {
    param_3 = r_llc_llcp_channel_map_ind_ack;
  }
  else if (bVar1 == 0x18) {
    iVar4 = r_sdk_config_get_opts_ext();
    param_3 = llc_llcp_phy_update_ind_ack;
    if (*(char *)(iVar4 + 0x18) == '\0') {
      r_assert_err(0,"llc_llcp.c",0x1e7);
    }
  }
  if (param_2 == (byte *)0x0) {
    uVar6 = 0xffff;
  }
  else {
    iVar4 = *(int *)(&llc_env + param_1 * 4);
    uVar6 = (uint)*param_2;
    if ((iVar4 != 0) && (uVar6 < 0x23)) {
      auStack_22[0] = *(ushort *)(&DAT_0001077c + uVar6 * 0xc);
      iVar2 = r_ke_malloc(auStack_22[0] + 0xc,2);
      bVar1 = *param_2;
      *(code **)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,auStack_22,0x30,(&PTR__LC1_00010778)[(uint)bVar1 * 3]
                            );
      if (iVar3 == 0) {
        *(char *)(iVar2 + 8) = (char)auStack_22[0];
        r_co_list_push_back(iVar4 + 0x28,iVar2);
        r_llc_llcp_tx_check(param_1);
        return;
      }
      uVar6 = (uint)*param_2;
      uVar5 = 0x32b;
      param_1 = iVar3;
      goto _L52;
    }
  }
  uVar5 = 0x339;
_L52:
  r_assert_param(param_1,uVar6,"llc_llcp.c",uVar5);
  return;
}

