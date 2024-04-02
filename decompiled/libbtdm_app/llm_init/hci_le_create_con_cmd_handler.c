/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> llm_init.o -> hci_le_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_create_con_cmd_handler(ushort *param_1,undefined4 param_2)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  byte bStack_a1;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  ushort uStack_90;
  undefined2 uStack_8e;
  uint uStack_8c;
  undefined2 uStack_88;
  undefined4 uStack_80;
  undefined2 uStack_7c;
  undefined1 auStack_7a [6];
  undefined1 auStack_74 [5];
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  byte bStack_6d;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  ushort uStack_68;
  ushort uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  ushort uStack_60;
  ushort uStack_5e;
  undefined1 uStack_44;
  
  bStack_a1 = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if ((uint)*(byte *)(iVar6 + 0xd) <= (uint)bStack_a1) break;
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_a1 * 0x44 + 0x40) == '\x05') break;
      bStack_a1 = bStack_a1 + 1;
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar6 + 0xd) <= bStack_a1) {
      if ((char)param_1[2] == '\0') {
        iVar7 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                          (param_1 + 3,*(undefined1 *)((int)param_1 + 5),
                           *(code **)(_r_ip_funcs_p + 0x4d8));
        iVar6 = 0xb;
        if (iVar7 != 0) goto _L39;
      }
      if (param_1[1] <= *param_1) {
        uVar9 = (uint)param_1[8];
        if ((((((param_1[7] <= uVar9) && ((ushort)(param_1[1] - 4) < 0x3ffd)) &&
              ((ushort)(*param_1 - 4) < 0x3ffd)) &&
             ((param_1[0xb] <= param_1[0xc] && (5 < param_1[7])))) &&
            ((uVar9 < 0xc81 && (((param_1[10] - 10 & 0xffff) < 0xc77 && (param_1[9] < 500)))))) &&
           (*(byte *)((int)param_1 + 5) < 4)) {
          if ((((byte)param_1[6] < 4) && ((param_1[9] + 1) * uVar9 < (uint)param_1[10] << 2)) &&
             ((((byte)param_1[6] & 1) == 0 ||
              (iVar6 = (*(code *)*_r_modules_funcs_p)
                                 (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
              iVar6 == 0)))) {
            iVar6 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                              (&bStack_a1,*(code **)(_r_ip_funcs_p + 0x4ac));
            if (iVar6 != 0) goto _L39;
            uStack_a0 = (uint)param_1[7] << 1;
            uVar9 = (uint)param_1[0xb];
            if (uStack_a0 < param_1[0xb]) {
              uVar9 = uStack_a0;
            }
            if (uVar9 < 2) {
              uVar9 = 2;
            }
            uStack_9c = (uint)param_1[8] << 1;
            uVar11 = (uint)param_1[0xc];
            if (uStack_9c < param_1[0xc]) {
              uVar11 = uStack_9c;
            }
            if (uVar11 < 2) {
              uVar11 = 2;
            }
            uStack_90 = (ushort)bStack_a1;
            uStack_8e = 0;
            uStack_98 = uVar9;
            uStack_94 = uVar11;
            iVar7 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                              (&uStack_a0,0,*(code **)(_r_ip_funcs_p + 0x6f8));
            iVar6 = 0xd;
            if (iVar7 != 0) goto _L39;
            if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_a1 * 0x44) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))("llm_init.c",0xc3,*(code **)(_r_plf_funcs_p + 8));
            }
            uVar4 = (uint)bStack_a1;
            iVar6 = *(int *)(_p_llm_env + 8);
            uVar8 = (*(code *)_r_modules_funcs_p[0x32])(0,0,0,0x3a,(code *)_r_modules_funcs_p[0x32])
            ;
            *(undefined4 *)(iVar6 + uVar4 * 0x44) = uVar8;
            iVar6 = _p_llm_env;
            puVar10 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_a1 * 0x44);
            puVar5 = (undefined1 *)*puVar10;
            if (puVar5 != (undefined1 *)0x0) {
              puVar5[9] = 1;
              *(ushort *)(puVar5 + 10) = *param_1;
              *(ushort *)(puVar5 + 0xc) = param_1[1];
              *puVar5 = (char)param_1[2];
              cVar1 = (char)param_1[6];
              puVar5[1] = cVar1;
              puVar5[2] = *(undefined1 *)((int)param_1 + 5);
              memcpy(puVar5 + 3,param_1 + 3,6);
              *(ushort *)(puVar5 + 0xe) = param_1[7];
              *(ushort *)(puVar5 + 0x10) = param_1[8];
              *(ushort *)(puVar5 + 0x12) = param_1[9];
              uVar2 = param_1[10];
              *(short *)(puVar5 + 0x16) = (short)uVar9;
              *(short *)(puVar5 + 0x18) = (short)uVar11;
              *(ushort *)(puVar5 + 0x14) = uVar2;
              if (cVar1 == '\x01') {
_L35:
                memcpy(puVar10 + 1,(void *)(iVar6 + 0x12),6);
              }
              else if ((cVar1 == '\0') || (cVar1 == '\x02')) {
                puVar10[1] = *(undefined4 *)(iVar6 + 0xc);
                *(undefined2 *)(puVar10 + 2) = *(undefined2 *)(iVar6 + 0x10);
              }
              else {
                if (cVar1 == '\x03') goto _L35;
                (**(code **)(_r_plf_funcs_p + 0xc))
                          (cVar1,0,"llm_init.c",0xed,*(code **)(_r_plf_funcs_p + 0xc));
              }
            }
            bVar3 = bStack_a1;
            iVar6 = _p_llm_env;
            uVar9 = (uint)bStack_a1;
            iVar7 = uVar9 * 0x44;
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar7 + 0x40) = 5;
            memcpy(auStack_7a,param_1 + 3,6);
            memcpy(auStack_74,(void *)(iVar6 + 0x1d),5);
            uStack_6e = 1;
            uStack_68 = *param_1;
            bStack_6d = bVar3;
            uStack_66 = param_1[1];
            uStack_64 = (undefined2)(uStack_8c >> 1);
            uStack_62 = uStack_88;
            uStack_60 = param_1[9];
            uStack_5e = param_1[10];
            uStack_6c = (undefined1)param_1[6];
            uStack_6b = *(undefined1 *)((int)param_1 + 5);
            uStack_6a = (undefined1)param_1[2];
            iVar7 = *(int *)(iVar6 + 8) + iVar7;
            uStack_80 = *(undefined4 *)(iVar7 + 4);
            uStack_7c = *(undefined2 *)(iVar7 + 8);
            uStack_6f = 0;
            uStack_44 = *(undefined1 *)(iVar6 + 0xc6);
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,1,1);
            }
            iVar6 = (**(code **)(_r_ip_funcs_p + 0x494))
                              (&uStack_80,*(code **)(_r_ip_funcs_p + 0x494));
            if (iVar6 != 0) {
              iVar6 = 3;
            }
            goto _L39;
          }
        }
      }
      iVar6 = 0x12;
      goto _L39;
    }
  }
  iVar6 = 0xc;
_L39:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar6,*(code **)(_r_ip_funcs_p + 0x4bc));
  return 0;
}

