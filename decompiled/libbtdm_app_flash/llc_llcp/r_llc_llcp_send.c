/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uStack_22;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == (byte *)0x0) {
    uVar5 = 0xffff;
  }
  else {
    uVar5 = (uint)*param_2;
    if ((iVar6 != 0) && (uVar5 < 0x23)) {
      uStack_22 = *(ushort *)(llcp_pdu_handler + uVar5 * 0xc + 8);
      iVar2 = r_ke_malloc(uStack_22 + 0xc,2);
      bVar1 = *param_2;
      *(undefined4 *)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,&uStack_22,0x30,
                             *(undefined4 *)(llcp_pdu_handler + (uint)bVar1 * 0xc + 4));
      if (iVar3 != 0) {
        r_assert_param(*param_2,"llc_llcp.c",0x335);
      }
      iVar4 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar4 + 0x28) & 0x20) != 0) {
        iVar4 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar4 + 0x2c) < 2) {
          r_ble_log_internal_hex(0x20e30016,uStack_22,iVar2 + 9);
        }
      }
      if (iVar3 == 0) {
        *(char *)(iVar2 + 8) = (char)uStack_22;
        r_co_list_push_back(iVar6 + 0x28,iVar2);
        r_llc_llcp_tx_check_hack(param_1);
      }
      return;
    }
  }
  r_assert_param(param_1,uVar5,"llc_llcp.c",0x344);
  return;
}

