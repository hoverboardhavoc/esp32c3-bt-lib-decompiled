/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
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
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  int iVar12;
  
  iVar9 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar9 + 0x18) == '\0') {
    return 0;
  }
  bVar1 = *param_1;
  iVar9 = (uint)bVar1 * 0x44;
  iVar4 = *(int *)(_p_llm_env + 8) + iVar9;
  bVar2 = *(byte *)(iVar4 + 0x40);
  if (bVar2 != 0xe) {
    if ((bVar2 < 0xe) || (0x10 < bVar2)) {
      r_assert_err(0,"llm_scan.c",0xb6c);
    }
    else {
      uVar10 = *(undefined1 *)(iVar4 + 0x41);
      r_sch_plan_rem(iVar4 + 0xc);
      uVar5 = r_llm_dev_list_search(iVar4 + 4,uVar10);
      if (((uVar5 < 0xc) && (iVar12 = uVar5 * 10 + _p_llm_env, (*(byte *)(iVar12 + 0x2d) & 4) != 0))
         && (((int)(uint)*(ushort *)(iVar12 + 0x2a) >>
              (*(byte *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x28) & 0x1f) & 1U) != 0)) {
        r_lld_per_adv_list_add(iVar4 + 4,uVar10);
      }
      cVar3 = *(char *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40);
      if (cVar3 == '\x10') {
        r_llm_cmd_cmp_send(0x2046,0);
      }
      else if (cVar3 == '\x0f') {
        puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,4);
        *puVar7 = 0x10;
        *(ushort *)(puVar7 + 2) = (ushort)bVar1;
        r_hci_send_2_host();
      }
      if (*(short *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2a) != 0xff) {
        puVar6 = (ushort *)r_ke_msg_alloc(1,0,8);
        iVar4 = _p_llm_env;
        *puVar6 = (ushort)bVar1;
        uVar10 = 0x16;
        iVar4 = *(int *)(iVar4 + 8) + iVar9;
        if (*(char *)(iVar4 + 0x40) != '\x10') {
          uVar10 = 8;
        }
        *(undefined1 *)(puVar6 + 1) = uVar10;
        uVar10 = *(undefined1 *)(iVar4 + 0x29);
        puVar6[2] = 0;
        *(undefined1 *)(puVar6 + 3) = 0;
        *(undefined1 *)((int)puVar6 + 3) = uVar10;
        r_ke_msg_send();
      }
    }
    goto _L692;
  }
  if (param_1[1] == 0) {
    r_llm_cmd_cmp_send(0x2045,0,param_2,param_3);
    puVar8 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    uVar11 = 0x440e;
_L705:
    *puVar8 = uVar11;
    iVar4 = _p_llm_env;
    puVar8[1] = (ushort)bVar1;
    iVar4 = *(int *)(iVar4 + 8) + iVar9;
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
      uVar11 = 0x3e0e;
      goto _L705;
    }
    r_assert_param((uint)bVar1,"llm_scan.c",0xb61);
  }
  r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar9) + -0xc);
  *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar9) = 0;
_L692:
  *(undefined1 *)(iVar9 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
  return 0;
}

