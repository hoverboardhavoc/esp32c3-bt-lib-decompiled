/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_param_cmd_handler(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  int *piVar8;
  byte bStack_3d;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L241:
    iVar6 = 0xc;
    goto _L256;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 1;
  iVar6 = r_llm_adv_hdl_to_id(0xff,0);
  bStack_3d = (byte)iVar6;
  if (iVar6 == 0xff) {
    iVar6 = r_llm_activity_free_get(&bStack_3d);
    if (iVar6 != 0) goto _L256;
    r_llm_adv_set_dft_params(bStack_3d,0);
  }
  else if (*(char *)(iVar6 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01') goto _L241;
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
  bVar1 = (byte)param_1[2];
  if (bVar1 < 5) {
    if (bVar1 != 1) {
      if (((param_1[1] < *param_1) || (*param_1 < 8)) || (0x4000 < param_1[1])) goto _L247;
    }
    if ((((byte)(*(char *)((int)param_1 + 0xd) - 1U) < 7) && ((byte)param_1[7] < 4)) &&
       (*(byte *)((int)param_1 + 5) < 4)) {
      if ((byte)param_1[3] < 2) {
        if (bVar1 == 1) {
_L248:
          iVar6 = r_co_bdaddr_compare((void *)((int)param_1 + 7),&co_null_bdaddr);
          if (iVar6 != 0) goto _L247;
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if (bVar1 == 4) goto _L248;
        }
        iVar6 = _p_llm_env;
        piVar8 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
        iVar5 = *piVar8;
        *(ushort *)(iVar5 + 2) = (ushort)(byte)(&adv_evt_type2prop)[(byte)param_1[2]];
        uVar3 = param_1[1];
        *(undefined1 *)(iVar5 + 9) = 0;
        *(char *)(iVar5 + 8) = (char)(uVar3 >> 8);
        *(char *)(iVar5 + 7) = (char)uVar3;
        uVar3 = *param_1;
        *(undefined1 *)(iVar5 + 6) = 0;
        *(ushort *)(iVar5 + 4) = uVar3;
        *(undefined1 *)(iVar5 + 10) = *(undefined1 *)((int)param_1 + 0xd);
        cVar2 = *(char *)((int)param_1 + 5);
        *(char *)(iVar5 + 0xb) = cVar2;
        *(char *)(iVar5 + 0xc) = (char)param_1[3];
        memcpy((void *)(iVar5 + 0xd),(void *)((int)param_1 + 7),6);
        uVar7 = 0;
        if (!bVar4) {
          uVar7 = (undefined1)param_1[7];
        }
        *(undefined1 *)(iVar5 + 0x13) = uVar7;
        if (cVar2 == '\x01') {
_L251:
          memcpy(piVar8 + 1,(void *)(iVar6 + 0x12),6);
        }
        else if ((cVar2 == '\0') || (cVar2 == '\x02')) {
          piVar8[1] = *(int *)(iVar6 + 0xc);
          *(undefined2 *)(piVar8 + 2) = *(undefined2 *)(iVar6 + 0x10);
        }
        else {
          if (cVar2 == '\x03') goto _L251;
          r_assert_param(cVar2,0,"llm_adv.c",0xe8);
        }
        piVar8 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
        *(undefined1 *)(piVar8 + 0x10) = 1;
        if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0)) {
          iVar6 = *piVar8;
          uStack_34 = 0;
          uStack_3c = (uint)*(byte *)(iVar6 + 9) << 0x10 | (uint)*(byte *)(iVar6 + 8) << 8 |
                      (uint)*(byte *)(iVar6 + 7);
          uStack_38 = (uint)*(byte *)(iVar6 + 10);
          (**(code **)(_bt_rf_coex_hooks_p + 4))(0,&uStack_3c);
        }
        iVar6 = 0;
        goto _L256;
      }
    }
  }
_L247:
  iVar6 = 0x12;
_L256:
  r_llm_cmd_cmp_send(param_2,iVar6);
  return 0;
}

