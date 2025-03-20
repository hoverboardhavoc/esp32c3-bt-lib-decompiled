/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  int iVar12;
  
  bVar1 = *param_1;
  iVar4 = (uint)bVar1 * 0x44;
  iVar5 = *(int *)(_p_llm_env + 8) + iVar4;
  bVar2 = *(byte *)(iVar5 + 0x40);
  if (bVar2 != 0xe) {
    if ((bVar2 < 0xe) || (0x10 < bVar2)) {
      r_assert_err(0,"llm_scan.c",0xb7a);
    }
    else {
      uVar10 = *(undefined1 *)(iVar5 + 0x41);
      r_sch_plan_rem(iVar5 + 0xc);
      uVar6 = r_llm_dev_list_search(iVar5 + 4,uVar10);
      if (uVar6 < 0xc) {
        iVar12 = uVar6 * 10 + _p_llm_env;
        if ((*(byte *)(iVar12 + 0x2d) & 4) != 0) {
          if (((int)(uint)*(ushort *)(iVar12 + 0x2a) >>
               (*(byte *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) & 0x1f) & 1U) != 0) {
            r_lld_per_adv_list_add(iVar5 + 4,uVar10);
          }
        }
      }
      cVar3 = *(char *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40);
      if (cVar3 == '\x10') {
        r_llm_cmd_cmp_send(0x2046,0);
      }
      else if (cVar3 == '\x0f') {
        puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,4);
        *puVar8 = 0x10;
        *(ushort *)(puVar8 + 2) = (ushort)bVar1;
        r_hci_send_2_host();
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2a) != 0xff) {
        puVar7 = (ushort *)r_ke_msg_alloc(1,0,8);
        iVar5 = _p_llm_env;
        *puVar7 = (ushort)bVar1;
        uVar10 = 0x16;
        iVar5 = *(int *)(iVar5 + 8) + iVar4;
        if (*(char *)(iVar5 + 0x40) != '\x10') {
          uVar10 = 8;
        }
        *(undefined1 *)(puVar7 + 1) = uVar10;
        uVar10 = *(undefined1 *)(iVar5 + 0x29);
        puVar7[2] = 0;
        *(undefined1 *)(puVar7 + 3) = 0;
        *(undefined1 *)((int)puVar7 + 3) = uVar10;
        r_ke_msg_send();
      }
    }
    goto _L696;
  }
  if (param_1[1] == 0) {
    r_llm_cmd_cmp_send(0x2045,0);
    puVar9 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    uVar11 = 0x440e;
_L709:
    *puVar9 = uVar11;
    iVar5 = _p_llm_env;
    puVar9[1] = (ushort)bVar1;
    iVar5 = *(int *)(iVar5 + 8) + iVar4;
    *(undefined1 *)(puVar9 + 2) = *(undefined1 *)(iVar5 + 0x28);
    *(undefined1 *)((int)puVar9 + 5) = *(undefined1 *)(iVar5 + 0x41);
    memcpy(puVar9 + 3,(void *)(iVar5 + 4),6);
    *(undefined1 *)(puVar9 + 6) = 1;
    puVar9[7] = 6;
    *(undefined1 *)(puVar9 + 8) = 0;
    r_hci_send_2_host(puVar9);
  }
  else {
    if (param_1[1] == 8) {
      puVar9 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
      uVar11 = 0x3e0e;
      goto _L709;
    }
    r_assert_param((uint)bVar1,"llm_scan.c",0xb6f);
  }
  r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar4) + -0xc);
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4) = 0;
_L696:
  *(undefined1 *)(iVar4 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
  return 0;
}

