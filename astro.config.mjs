// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

// https://astro.build/config
export default defineConfig({
	site: 'https://Psychol0g1st.github.io',
	base: '/cpp_learning',
	integrations: [
		starlight({
			title: 'My Docs',
			social: [{ icon: 'github', label: 'GitHub', href: 'https://github.com/withastro/starlight' }],
			sidebar: [
				{
					label: 'Anyagok',
					autogenerate: { directory: 'anyagok' },
				},
				{
					label: 'Feladatok',
					autogenerate: { directory: 'feladatok' },
				},
			],
		}),
	],
});
