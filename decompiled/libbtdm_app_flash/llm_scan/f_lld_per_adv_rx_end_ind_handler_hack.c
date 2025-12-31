/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_per_adv_rx_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_per_adv_rx_end_ind_handler_hack(byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  int iVar11;
  uint uVar12;
  
  bVar1 = *param_1;
  uVar12 = (uint)bVar1;
  iVar3 = uVar12 * 0x44;
  iVar4 = *(int *)(_p_llm_env + 8) + iVar3;
  uVar9 = *(undefined1 *)(iVar4 + 0x41);
  if (*(char *)(iVar4 + 0x40) != '\x0e') {
    if ((byte)(*(char *)(iVar4 + 0x40) - 0xfU) < 2) {
      r_sch_plan_rem(iVar4 + 0xc);
      uVar5 = r_llm_dev_list_search(iVar4 + 4,uVar9);
      if (uVar5 < 0xc) {
        iVar11 = uVar5 * 10 + _p_llm_env;
        if ((*(byte *)(iVar11 + 0x2d) & 4) != 0) {
          if (((int)(uint)*(ushort *)(iVar11 + 0x2a) >>
               (*(byte *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x28) & 0x1f) & 1U) != 0) {
            r_lld_per_adv_list_add(iVar4 + 4,uVar9);
          }
        }
      }
      cVar2 = *(char *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40);
      if (cVar2 == '\x10') {
        r_llm_cmd_cmp_send(0x2046,0);
      }
      else if (cVar2 == '\x0f') {
        puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,4);
        *puVar7 = 0x10;
        *(ushort *)(puVar7 + 2) = (ushort)bVar1;
        r_hci_send_2_host();
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2a) != 0xff) {
        puVar6 = (ushort *)r_ke_msg_alloc(1,0,8);
        iVar4 = _p_llm_env;
        *puVar6 = (ushort)bVar1;
        uVar9 = 0x16;
        iVar4 = *(int *)(iVar4 + 8) + iVar3;
        if (*(char *)(iVar4 + 0x40) != '\x10') {
          uVar9 = 8;
        }
        *(undefined1 *)(puVar6 + 1) = uVar9;
        uVar9 = *(undefined1 *)(iVar4 + 0x29);
        puVar6[2] = 0;
        *(undefined1 *)(puVar6 + 3) = 0;
        *(undefined1 *)((int)puVar6 + 3) = uVar9;
        r_ke_msg_send();
      }
    }
    else {
      r_assert_err(0,"llm_scan.c",0xbcf);
    }
    goto _L678;
  }
  if (param_1[1] == 0) {
    r_llm_cmd_cmp_send(0x2045,0);
    puVar8 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    uVar10 = 0x440e;
_L691:
    *puVar8 = uVar10;
    iVar4 = _p_llm_env;
    puVar8[1] = (ushort)bVar1;
    iVar4 = *(int *)(iVar4 + 8) + iVar3;
    *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(iVar4 + 0x28);
    *(undefined1 *)((int)puVar8 + 5) = *(undefined1 *)(iVar4 + 0x41);
    memcpy(puVar8 + 3,(void *)(iVar4 + 4),6);
    *(undefined1 *)(puVar8 + 6) = 1;
    puVar8[7] = 6;
    *(undefined1 *)(puVar8 + 8) = 0;
    r_hci_send_2_host(puVar8);
  }
  else {
    if (param_1[1] == 8) {
      puVar8 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
      uVar10 = 0x3e0e;
      goto _L691;
    }
    r_assert_param(uVar12,"llm_scan.c",0xbc4);
  }
  r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar3) + -0xc);
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3) = 0;
_L678:
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 0;
  r_ble_log_internal_x1(0x404e01f3,uVar12);
  return 0;
}

