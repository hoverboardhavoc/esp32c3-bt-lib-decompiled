/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  
  iVar6 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L6:
    iVar6 = 0xc;
    goto _L21;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 1;
  iVar6 = (**(code **)(iVar6 + 0x544))(0xff,0,*(code **)(iVar6 + 0x544));
  bStack_3d = (byte)iVar6;
  if (iVar6 == 0xff) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_3d,*(code **)(_r_ip_funcs_p + 0x4ac));
    if (iVar6 != 0) goto _L21;
    (**(code **)(_r_ip_funcs_p + 0x54c))(bStack_3d,0,*(code **)(_r_ip_funcs_p + 0x54c));
  }
  else if (*(char *)(iVar6 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01') goto _L6;
  bVar1 = (byte)param_1[2];
  if (bVar1 < 5) {
    if (bVar1 != 1) {
      if (((param_1[1] < *param_1) || (*param_1 < 0x20)) || (0x4000 < param_1[1])) goto _L12;
    }
    if ((((byte)(*(char *)((int)param_1 + 0xd) - 1U) < 7) && ((byte)param_1[7] < 4)) &&
       ((*(byte *)((int)param_1 + 5) < 4 && ((byte)param_1[3] < 2)))) {
      if ((bVar1 == 1) || (bVar4 = false, bVar1 == 4)) {
        iVar6 = (*(code *)*_r_modules_funcs_p)
                          ((void *)((int)param_1 + 7),&co_null_bdaddr,(code *)*_r_modules_funcs_p);
        if (iVar6 != 0) goto _L12;
        bVar4 = true;
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
_L16:
        memcpy(piVar8 + 1,(void *)(iVar6 + 0x12),6);
      }
      else if ((cVar2 == '\0') || (cVar2 == '\x02')) {
        piVar8[1] = *(int *)(iVar6 + 0xc);
        *(undefined2 *)(piVar8 + 2) = *(undefined2 *)(iVar6 + 0x10);
      }
      else {
        if (cVar2 == '\x03') goto _L16;
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (cVar2,0,"llm_adv.c",0xe0,*(code **)(_r_plf_funcs_p + 0xc));
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
      goto _L21;
    }
  }
_L12:
  iVar6 = 0x12;
_L21:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar6,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

