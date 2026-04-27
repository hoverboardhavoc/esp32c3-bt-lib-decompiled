/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> lld_per_adv_rx_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_rx_end_ind_handler_hack(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  int iVar11;
  uint uVar12;
  
  iVar8 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar8 + 0x18) == '\0') {
    return 0;
  }
  bVar1 = *param_1;
  uVar12 = (uint)bVar1;
  iVar8 = uVar12 * 0x44;
  iVar3 = *(int *)(_p_llm_env + 8) + iVar8;
  uVar9 = *(undefined1 *)(iVar3 + 0x41);
  if (*(char *)(iVar3 + 0x40) != '\x0e') {
    if ((byte)(*(char *)(iVar3 + 0x40) - 0xfU) < 2) {
      r_sch_plan_rem(iVar3 + 0xc);
      uVar4 = r_llm_dev_list_search(iVar3 + 4,uVar9);
      if (((uVar4 < 0xc) && (iVar11 = uVar4 * 10 + _p_llm_env, (*(byte *)(iVar11 + 0x2d) & 4) != 0))
         && (((int)(uint)*(ushort *)(iVar11 + 0x2a) >>
              (*(byte *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x28) & 0x1f) & 1U) != 0)) {
        r_lld_per_adv_list_add(iVar3 + 4,uVar9);
      }
      cVar2 = *(char *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40);
      if (cVar2 == '\x10') {
        r_llm_cmd_cmp_send(0x2046,0);
      }
      else if (cVar2 == '\x0f') {
        puVar6 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,4);
        *puVar6 = 0x10;
        *(ushort *)(puVar6 + 2) = (ushort)bVar1;
        r_hci_send_2_host();
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x2a) != 0xff) {
        puVar5 = (ushort *)r_ke_msg_alloc(1,0,8);
        iVar3 = _p_llm_env;
        *puVar5 = (ushort)bVar1;
        uVar9 = 0x16;
        iVar3 = *(int *)(iVar3 + 8) + iVar8;
        if (*(char *)(iVar3 + 0x40) != '\x10') {
          uVar9 = 8;
        }
        *(undefined1 *)(puVar5 + 1) = uVar9;
        uVar9 = *(undefined1 *)(iVar3 + 0x29);
        puVar5[2] = 0;
        *(undefined1 *)(puVar5 + 3) = 0;
        *(undefined1 *)((int)puVar5 + 3) = uVar9;
        r_ke_msg_send();
      }
    }
    else {
      r_assert_err(0,"llm_scan.c",0xbef);
    }
    goto _L681;
  }
  if (param_1[1] == 0) {
    llm_sync_cancel_cc_act_id = 0xff;
    r_llm_cmd_cmp_send(0x2045,0,param_2,param_3);
    puVar7 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    uVar10 = 0x440e;
_L694:
    *puVar7 = uVar10;
    iVar3 = _p_llm_env;
    puVar7[1] = (ushort)bVar1;
    iVar3 = *(int *)(iVar3 + 8) + iVar8;
    *(undefined1 *)(puVar7 + 2) = *(undefined1 *)(iVar3 + 0x28);
    *(undefined1 *)((int)puVar7 + 5) = *(undefined1 *)(iVar3 + 0x41);
    memcpy(puVar7 + 3,(void *)(iVar3 + 4),6);
    *(undefined1 *)(puVar7 + 6) = 1;
    puVar7[7] = 6;
    *(undefined1 *)(puVar7 + 8) = 0;
    r_hci_send_2_host(puVar7);
  }
  else {
    if (param_1[1] == 8) {
      llm_sync_cancel_cc_act_id = 0xff;
      puVar7 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
      uVar10 = 0x3e0e;
      goto _L694;
    }
    r_assert_param(uVar12,"llm_scan.c",0xbe4);
  }
  r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar8) + -0xc);
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar8) = 0;
_L681:
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40) = 0;
  r_ble_log_internal_x1(0x404e021e,uVar12);
  return 0;
}

