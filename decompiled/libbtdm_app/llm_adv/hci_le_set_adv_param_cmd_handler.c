/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_param_cmd_handler(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int *piVar7;
  byte bStack_3d;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  
  iVar5 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L7:
    iVar5 = 0xc;
    goto _L23;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 1;
  iVar5 = (**(code **)(iVar5 + 0x544))(0xff,0,*(code **)(iVar5 + 0x544));
  bStack_3d = (byte)iVar5;
  if (iVar5 == 0xff) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_3d,*(code **)(_r_ip_funcs_p + 0x4ac));
    if (iVar5 != 0) goto _L23;
    (**(code **)(_r_ip_funcs_p + 0x54c))(bStack_3d,0,*(code **)(_r_ip_funcs_p + 0x54c));
  }
  else if (*(char *)(*(int *)(_p_llm_env + 8) + iVar5 * 0x44 + 0x40) != '\x01') goto _L7;
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
  bVar1 = (byte)param_1[2];
  if (bVar1 < 5) {
    if (bVar1 != 1) {
      if (((param_1[1] < *param_1) || (*param_1 < 8)) || (0x4000 < param_1[1])) goto _L13;
    }
    if ((((byte)(*(char *)((int)param_1 + 0xd) - 1U) < 7) && ((byte)param_1[7] < 4)) &&
       ((*(byte *)((int)param_1 + 5) < 4 && ((byte)param_1[3] < 2)))) {
      if ((bVar1 == 1) || (bVar3 = false, bVar1 == 4)) {
        iVar5 = (*(code *)*_r_modules_funcs_p)
                          ((void *)((int)param_1 + 7),&co_null_bdaddr,(code *)*_r_modules_funcs_p);
        if (iVar5 != 0) goto _L13;
        bVar3 = true;
      }
      iVar5 = _p_llm_env;
      piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
      iVar4 = *piVar7;
      bVar1 = (&adv_evt_type2prop)[(byte)param_1[2]];
      *(undefined1 *)(iVar4 + 9) = 0;
      *(ushort *)(iVar4 + 2) = (ushort)bVar1;
      uVar2 = param_1[1];
      *(undefined1 *)(iVar4 + 6) = 0;
      *(char *)(iVar4 + 8) = (char)(uVar2 >> 8);
      *(char *)(iVar4 + 7) = (char)uVar2;
      *(ushort *)(iVar4 + 4) = *param_1;
      *(undefined1 *)(iVar4 + 10) = *(undefined1 *)((int)param_1 + 0xd);
      bVar1 = *(byte *)((int)param_1 + 5);
      *(byte *)(iVar4 + 0xb) = bVar1;
      *(char *)(iVar4 + 0xc) = (char)param_1[3];
      memcpy((void *)(iVar4 + 0xd),(void *)((int)param_1 + 7),6);
      uVar6 = 0;
      if (!bVar3) {
        uVar6 = (undefined1)param_1[7];
      }
      *(undefined1 *)(iVar4 + 0x13) = uVar6;
      if (bVar1 == 2) {
_L17:
        piVar7[1] = *(int *)(iVar5 + 0xc);
        *(undefined2 *)(piVar7 + 2) = *(undefined2 *)(iVar5 + 0x10);
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) goto _L17;
_L19:
        memcpy(piVar7 + 1,(void *)(iVar5 + 0x12),6);
      }
      else {
        if (bVar1 == 3) goto _L19;
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (bVar1,0,"llm_adv.c",0xe8,*(code **)(_r_plf_funcs_p + 0xc));
      }
      piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
      *(undefined1 *)(piVar7 + 0x10) = 1;
      if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0)) {
        iVar5 = *piVar7;
        uStack_34 = 0;
        uStack_3c = (uint)*(byte *)(iVar5 + 9) << 0x10 | (uint)*(byte *)(iVar5 + 8) << 8 |
                    (uint)*(byte *)(iVar5 + 7);
        uStack_38 = (uint)*(byte *)(iVar5 + 10);
        (**(code **)(_bt_rf_coex_hooks_p + 4))(0,&uStack_3c);
      }
      iVar5 = 0;
      goto _L23;
    }
  }
_L13:
  iVar5 = 0x12;
_L23:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

